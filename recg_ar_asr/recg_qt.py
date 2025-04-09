import onnxruntime as ort
# import onnx
import numpy as np
import sys
import librosa
import os
import json
import subprocess
from pydub import AudioSegment
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QTextEdit, QFileDialog

os.system('chcp 65001')  # 设置命令行的编码为UTF-8


class AppDemo(QWidget):

    def __init__(self):
        super().__init__()
        self.setWindowTitle("语音与声纹识别")
        self.resize(500, 300)
        layout = QVBoxLayout()
        self.text_edit = QTextEdit(self)
        layout.addWidget(self.text_edit)

        self.btn_upload = QPushButton("上传音频文件夹, 并执行声纹识别", self)
        self.btn_upload.clicked.connect(self.speaker_recg)
        layout.addWidget(self.btn_upload)

        self.btn_run = QPushButton('上传音频文件, 并执行语音识别', self)
        self.btn_run.clicked.connect(self.speech_recg)
        layout.addWidget(self.btn_run)

        self.setLayout(layout)

    def extract_features(self, file_path):
        audio, sr = librosa.load(file_path)
        mfccs = librosa.feature.mfcc(y=audio, sr=sr, n_mfcc=40)
        mfccs_mean = np.mean(mfccs.T, axis=0)
        return mfccs_mean

    def from_wav_to_result(self, speaker_folder):
        # 读取模型
        onnx_path = "local/models/final_lstm_64_class_dynamic.onnx"
        # 检验onnx模型格式
        # onnx_model = onnx.load(onnx_path)
        # onnx.checker.check_model(onnx_model)
        speaker_rec_model = ort.InferenceSession(onnx_path)

        features = []
        for one_wav in os.listdir(speaker_folder):
            if one_wav.endswith(".wav"):
                wav_path = os.path.join(speaker_folder, one_wav)
                one_feature = self.extract_features(
                    wav_path)  # 特征维度 需要经过scale处理
                # 使用和训练数据相同的scale处理
                mean = np.load("local/data/mean.npy")
                scale = np.load("local/data/scale.npy")
                one_feature = (one_feature - mean) / scale
                one_feature = one_feature.astype(np.float32)

                features.append(one_feature)

        features = np.vstack(features)

        # 将数据调整成8个
        if features.shape[0] < 8:
            features = np.pad(
                features, ((0, 8 - features.shape[0]), (0, 0)), mode="wrap")
        elif features.shape[0] > 8:
            features = features[:8, :]

        features = np.expand_dims(features, axis=0)  # 增加 batch 维度
        print(f"features.shape: {features.shape}")

        # 运行推理
        input_name = speaker_rec_model.get_inputs()[0].name
        result = speaker_rec_model.run(None, {input_name: features})
        result = np.round(result)

        print(f"pred:{result[0][0][0]}")  # 输出了结果，说明输入形状没问题
        return result[0][0][0]

    def speaker_recg(self):
        speaker_folder = QFileDialog.getExistingDirectory(self, "选择一个人的音频文件夹")
        if speaker_folder:
            label = int(speaker_folder[-2:])
            pred_res = self.from_wav_to_result(speaker_folder)
            self.text_edit.setText(f"真实说话者: {label};  模型识别说话者: {pred_res}\n")

    def convert_to_sherpa_onnx_wav(self, input_file, output_file):
        audio = AudioSegment.from_file(input_file)
        audio = audio.set_channels(1)
        audio = audio.set_sample_width(2)
        audio.export(output_file, format="wav")

    def from_stdout_to_json_dump(self, result):
        if '{"text"' in result.stderr:
            output_lines = result.stderr.split('\n')
        else:
            output_lines = result.stdout.split('\n')

        json_part = None
        for line in output_lines:
            if line.startswith('{"text"'):
                json_part = line
                break

        ret = result.stdout + "\n" + result.stderr
        if json_part:
            json_data = json.loads(json_part)
            ret = json.dumps(
                json_data, indent=4, ensure_ascii=False)
        return ret

    def speech_recg(self):
        # 获取打包后的临时路径
        if hasattr(sys, '_MEIPASS'):
            base_path = sys._MEIPASS
        else:
            base_path = os.path.dirname(__file__)

        sherpa_path = os.path.join(base_path, 'sherpa-onnx')
        print(sherpa_path)

        input_audio, _ = QFileDialog.getOpenFileName(
            self, "选择文件", "/", "WAV Files (*.wav);;All Files (*)")

        if not input_audio:  # 检查是否选择了文件
            self.text_edit.setText("未选择文件")
            return

        self.text_edit.setText(f"the input: {input_audio}")
        temp_names = input_audio.split('.')
        audio = temp_names[0]+"_for_recg.wav"
        self.convert_to_sherpa_onnx_wav(input_audio, audio)

        # 运行命令，显示结果
        if audio:
            command = [
                os.path.join(base_path, 'sherpa-onnx', 'build',
                             'bin', 'sherpa-onnx-offline.exe'),
                '--tokens=' +
                os.path.join(
                    base_path, 'sherpa-onnx', 'sherpa-onnx-paraformer-zh-2024-03-09', 'tokens.txt'),
                '--paraformer=' +
                os.path.join(
                    base_path, 'sherpa-onnx', 'sherpa-onnx-paraformer-zh-2024-03-09', 'model.onnx'),
                audio
            ]
            try:
                result = subprocess.run(
                    command, capture_output=True, text=True, encoding='utf-8', shell=True)
                show_text = self.from_stdout_to_json_dump(result=result)
                self.text_edit.setText(show_text)
            except Exception as e:
                self.text_edit.setText(f'命令执行失败: {e}')
        else:
            self.text_edit.setText("未选择文件")


def run_qt():
    app = QApplication(sys.argv)
    demo = AppDemo()
    demo.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    run_qt()
