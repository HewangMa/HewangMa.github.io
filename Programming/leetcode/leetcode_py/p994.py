from collections import deque


class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])

        q = deque()
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == 2:
                    q.append((i, j, 0))

        def neighbor(i, j):
            for ii, jj in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
                if 0 <= ii < self.m and 0 <= jj < self.n:
                    yield ii, jj

        d = 0
        while q:
            i, j, d = q.popleft()
            for ii, jj in neighbor(i, j):
                if grid[ii][jj] == 1:
                    grid[ii][jj] = 2
                    q.append((ii, jj, d + 1))

        # 传播完了还有1
        if any(1 in row for row in grid):
            return -1
        return d
