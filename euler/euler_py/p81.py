import numpy as np

file = '0081_matrix.txt'
data = np.loadtxt(file, delimiter=',')
minPathSum = [[0 for _ in range(80)] for _ in range(80)]
minPathSum[0][0] = data[0][0]
for j in range(1, 80):
    minPathSum[0][j] = minPathSum[0][j - 1] + data[0][j]
    minPathSum[j][0] = minPathSum[j - 1][0] + data[j][0]
for i in range(1,80):
    for j in range(1,80):
        minPathSum[i][j]=min(minPathSum[i-1][j],minPathSum[i][j-1])+data[i][j]
print(minPathSum[79][79])

# print(minPathSum)
# print(data)
