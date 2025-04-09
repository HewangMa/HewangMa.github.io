import heapq

import numpy as np


class PriorityQueue:
    def __init__(self):
        self.elements = []

    def is_empty(self):
        return len(self.elements) == 0

    def put(self, item):
        heapq.heappush(self.elements, (item[2], item))

    def get(self):
        return heapq.heappop(self.elements)[1]


Q = PriorityQueue()

file = '0083_matrix.txt'
data = np.loadtxt(file, delimiter=',')
visited = [[0 for _ in range(80)] for _ in range(80)]
Q.put((0, 0, data[0][0]))
while not Q.is_empty():
    cell = Q.get()
    i, j, currentPathSum = cell[0], cell[1], cell[2]
    if visited[i][j] == 1: continue
    visited[i][j] = 1
    if i == j == 79:
        print(currentPathSum)
        exit()
    if i > 0 and visited[i - 1][j] == 0: Q.put((i - 1, j, currentPathSum + data[i - 1][j]))
    if j > 0 and visited[i][j - 1] == 0: Q.put((i, j - 1, currentPathSum + data[i][j - 1]))
    if i < 79 and visited[i + 1][j] == 0: Q.put((i + 1, j, currentPathSum + data[i + 1][j]))
    if j < 79 and visited[i][j + 1] == 0: Q.put((i, j + 1, currentPathSum + data[i][j + 1]))
