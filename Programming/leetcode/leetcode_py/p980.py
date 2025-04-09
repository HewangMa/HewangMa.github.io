class Solution:

    def __init__(self) -> None:
        self.visited = [[0 for _ in range(22)] for _ in range(22)]
        self.dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        self.ans = 0
        self.pathLen = 0
        self.Num0 = 1
        self.n = 0
        self.m = 0

    def valid(self, i, j) -> bool:
        return i >= 0 and i < self.n and j >= 0 and j < self.m

    def dfs(self, grid: list[list[int]], i, j):
        if grid[i][j] == 2:
            if self.pathLen == self.Num0:
                self.ans += 1
            return

        self.visited[i][j] = 1
        for k in range(4):
            ii = i + self.dir[k][0]
            jj = j + self.dir[k][1]
            if (
                (not self.valid(ii, jj))
                or self.visited[ii][jj] == 1
                or grid[ii][jj] == -1
            ):
                continue
            self.visited[ii][jj] = 1
            self.pathLen += 1
            self.dfs(grid, ii, jj)
            self.pathLen -= 1
            self.visited[ii][jj] = 0

    def uniquePathsIII(self, grid: list[list[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] == 0:
                    self.Num0 += 1

        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] == 1:
                    self.dfs(grid, i, j)
        print(self.ans)
        return self.ans


if __name__ == "__main__":
    s = Solution()
    board = [[1, 2]]
    s.uniquePathsIII(board)
