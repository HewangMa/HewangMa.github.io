import os
from pydub import AudioSegment

def convert_to_sherpa_onnx_wav(input_file, output_file):
    audio = AudioSegment.from_file(input_file)
    audio = audio.set_channels(1)
    audio = audio.set_sample_width(2)
    audio.export(output_file, format="wav")
    print("ok?")

folder=os.path.join(".","sherpa-onnx",'self_test')
for wav in os.listdir(folder):
    wav_path=os.path.join(folder,wav)
    convert_to_sherpa_onnx_wav(wav_path, wav_path)
