import numpy as np

file = '0082_matrix.txt'
data = np.loadtxt(file, delimiter=',')
minPathSum = [[0 for _ in range(80)] for _ in range(80)]
for i in range(80):
    minPathSum[i][0] = data[i][0]
for j in range(1, 80):
    # get the pre sum in this col first
    preSum = [data[0][j], ]
    for i in range(1, 80):
        preSum.append(preSum[-1] + data[i][j])

    # then find the min path to this number
    for i in range(80):
        minPathSum[i][j] = minPathSum[i][j - 1] + data[i][j]
        for ii in range(i):
            minPathSum[i][j] = (min(minPathSum[i][j], minPathSum[ii][j - 1] + preSum[i] - preSum[ii] + data[ii][j]))
        for ii in range(i + 1, 80):
            minPathSum[i][j] = (min(minPathSum[i][j], minPathSum[ii][j - 1] + preSum[ii] - preSum[i] + data[i][j]))
ret = minPathSum[0][79]
for i in range(80):
    ret = min(ret, minPathSum[i][79])
print(ret)
# print(minPathSum)
# print(data)
