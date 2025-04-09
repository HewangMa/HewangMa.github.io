import onnxruntime as ort
import onnx
import numpy as np
import sys
import librosa
import os
import json
import subprocess
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QTextEdit, QFileDialog

os.system('chcp 65001')  # 设置命令行的编码为UTF-8

# eval with onnx and without torch
onnx_path = "local/models/final_lstm_64_class_dynamic.onnx"
onnx_model = onnx.load(onnx_path)
onnx.checker.check_model(onnx_model)
speaker_rec_model = ort.InferenceSession(onnx_path)


def extract_features(file_path):
    audio, sr = librosa.load(file_path)
    mfccs = librosa.feature.mfcc(y=audio, sr=sr, n_mfcc=40)
    mfccs_mean = np.mean(mfccs.T, axis=0)
    return mfccs_mean


def from_wav_to_result(speaker_folder):

    features = []
    for one_wav in os.listdir(speaker_folder):
        if one_wav.endswith(".wav"):
            wav_path = os.path.join(speaker_folder, one_wav)
            one_feature = extract_features(wav_path)  # 特征维度 需要经过scale处理
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


class AppDemo(QWidget):

    def __init__(self):
        super().__init__()
        self.setWindowTitle("语音与声纹识别")
        self.resize(500, 300)
        layout = QVBoxLayout()
        self.text_edit = QTextEdit(self)
        layout.addWidget(self.text_edit)

        self.btn_upload = QPushButton("上传音频文件夹, 并执行声纹识别", self)
        self.btn_upload.clicked.connect(self.wav_for_speaker_recg)
        layout.addWidget(self.btn_upload)

        self.btn_run = QPushButton('上传音频文件, 并执行语音识别', self)
        self.btn_run.clicked.connect(self.wav_for_speech_recg)
        layout.addWidget(self.btn_run)

        self.setLayout(layout)

    def wav_for_speaker_recg(self):
        speaker_folder = QFileDialog.getExistingDirectory(self, "选择一个人的音频文件夹")
        if speaker_folder:
            label = int(speaker_folder[-2:])
            pred_res = from_wav_to_result(speaker_folder)
            self.text_edit.setText(f"真实说话者: {label};  模型识别说话者: {pred_res}\n")

    def wav_for_speech_recg(self):
        base_path = os.path.dirname(__file__)
        folder, _ = QFileDialog.getOpenFileName(
            self, "选择文件", "/", "WAV Files (*.wav);;All Files (*)")
        if folder:
            command = [
                os.path.join(base_path, 'sherpa-onnx', 'build',
                             'bin', 'sherpa-onnx-offline.exe'),
                '--tokens=' +
                os.path.join(
                    base_path, 'sherpa-onnx', 'sherpa-onnx-paraformer-zh-2024-03-09', 'tokens.txt'),
                '--paraformer=' +
                os.path.join(
                    base_path, 'sherpa-onnx', 'sherpa-onnx-paraformer-zh-2024-03-09', 'model.onnx'),
                folder
            ]
            try:
                result = subprocess.run(
                    command, capture_output=True, text=True, encoding='utf-8', shell=True)

                output_lines = result.stderr.split('\n')
                json_part = None
                for line in output_lines:
                    if line.startswith('{"text"'):
                        json_part = line
                        break
                if json_part:
                    json_data = json.loads(json_part)
                    formatted_json = json.dumps(
                        json_data, indent=4, ensure_ascii=False)
                    self.text_edit.setText(formatted_json)
                else:
                    self.text_edit.setText(
                        result.stdout + "\n" + result.stderr)

            except Exception as e:
                self.text_edit.setText(f'命令执行失败: {e}')
        else:
            self.text_edit.setText("未选择文件")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    demo = AppDemo()
    demo.show()
    sys.exit(app.exec())
