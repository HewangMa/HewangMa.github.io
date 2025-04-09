import os
import librosa
from torch.utils.data import Dataset
import numpy as np


class VoiceDataset(Dataset):
    def __init__(self, data_path):
        self.data_path = data_path
        self.speakers = sorted(os.listdir(data_path))
        self.wav = []
        self.label = []
        for speaker in self.speakers:
            speaker_path = os.path.join(data_path, speaker)
            for wav in os.listdir(speaker_path):
                self.wav.append(os.path.join(speaker_path, wav))
                self.label.append(speaker)

    def extract_features(self, file_path):
        audio, sr = librosa.load(file_path)
        mfccs = librosa.feature.mfcc(y=audio, sr=sr, n_mfcc=40)
        mfccs_mean = np.mean(mfccs.T, axis=0)
        return mfccs_mean

    def __len__(self):
        return len(self.wav)

    def __getitem__(self, idx):
        return self.extract_features(self.wav[idx]), int(self.label[idx][-3:])


if __name__ == "__main__":
    data_path = os.path.join(
        os.path.dirname(os.path.dirname(__file__)), "data", "sr_data_whole"
    )
    train_path = os.path.join(data_path, "train")
    test_path = os.path.join(data_path, "test")

    train_loader = VoiceDataset(train_path)
    test_loader = VoiceDataset(test_path)

    print(f"Train size: {len(train_loader)}")
    for wav_mfcc, label in train_loader:
        print(f"wav_mfcc: {wav_mfcc}")
        print(f"label: {label}")
        exit()
