from torch import nn
import torch


class LSTM_net(nn.Module):
    def __init__(self, input_size=128, hidden_size=32, num_layers=1, nums_class=3):
        super(LSTM_net, self).__init__()
        self.lstm = nn.LSTM(input_size, hidden_size, num_layers, batch_first=True)
        self.fc = nn.Linear(hidden_size, nums_class)

    def forward(self, x):
        out, hidden = self.lstm(x)
        out = self.fc(out)
        return out


class NN_net(nn.Module):
    def __init__(self, input_size=20, hidden_size=16, num_classes=8):
        super(NN_net, self).__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.fc2 = nn.Linear(hidden_size, num_classes)
        self.relu = nn.ReLU()

    def forward(self, x):
        out = self.fc2(self.relu(self.fc1(x)))
        return out


class LSTMModel(nn.Module):
    def __init__(self, input_size=40, hidden_size=64, num_layers=3, output_size=1):
        super(LSTMModel, self).__init__()
        self.hidden_size = hidden_size
        self.num_layers = num_layers
        self.lstm = nn.LSTM(input_size, hidden_size, num_layers, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)

    def forward(self, x):
        h0 = torch.zeros(self.num_layers, x.size(0), self.hidden_size).to(x.device)
        c0 = torch.zeros(self.num_layers, x.size(0), self.hidden_size).to(x.device)
        out, _ = self.lstm(x, (h0, c0))
        out = self.fc(out[:, -1, :])
        return out
