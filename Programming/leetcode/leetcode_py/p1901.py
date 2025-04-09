import math


class Solution:
    def find_left(self, row):
        n = len(row)
        left, right = 0, n - 1
        while left < right:
            mid = math.ceil((left + right) / 2)
            if row[mid] < row[mid - 1]:
                right = mid - 1
            else:
                left = mid
        return right

    def find_right(self, row):
        n = len(row)
        left, right = 0, n - 1
        while left < right:
            mid = (left + right) // 2
            if row[mid] < row[mid + 1]:
                left = mid + 1
            else:
                right = mid
        return left

    def valid(self, mat, i, j):
        m, n = len(mat), len(mat[0])
        up = mat[i - 1][j] if i > 0 else -1
        down = mat[i + 1][j] if i < m - 1 else -1
        left = mat[i][j - 1] if j > 0 else -1
        right = mat[i][j + 1] if j < n - 1 else -1
        val = mat[i][j]
        return left < val and right < val and up < val and down < val

    def findPeakGrid(self, mat):
        m, n = len(mat), len(mat[0])
        for i in range(m):
            if self.valid(mat, i, 0):
                return [i, 0]
            if self.valid(mat, i, n - 1):
                return [i, n - 1]
        for j in range(n):
            if self.valid(mat, 0, j):
                return [0, j]
            if self.valid(mat, m - 1, j):
                return [m - 1, j]
        for i, row in enumerate(mat):
            left, right = self.find_left(row), self.find_right(row)
            if self.valid(mat, i, left):
                return [i, left]
            if self.valid(mat, i, right):
                return [i, right]


if __name__ == "__main__":
    mat = [
        [7, 2, 3, 1, 2],
        [6, 5, 4, 2, 1],
    ]
