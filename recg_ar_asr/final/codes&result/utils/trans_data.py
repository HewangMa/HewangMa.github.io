# import and set default
import os
import numpy as np
import pandas as pd
import dataset

base_path = os.path.dirname(os.path.dirname(__file__))
print(f"Base_path is {base_path} !!")


trans_path = os.path.join(base_path, "data", "sr_data", "train", "SPEECHDATA", "wav")
trans_dataset = dataset.VoiceDataset(trans_path)
total_batch_nums = len(trans_dataset)

data_array = np.empty((0, 41), dtype=float)
print(data_array.shape)

for i, (wav_mfcc, label) in enumerate(trans_dataset):
    wav_mfcc = np.append(wav_mfcc, label)
    data_array = np.vstack([data_array, wav_mfcc])
    if i % 1000 == 0:
        print(f" added {i} samples, data.shape: {data_array.shape}")

df = pd.DataFrame(data_array)
df.to_csv("data.csv", index=False)  # index=False 避免保存索引列
