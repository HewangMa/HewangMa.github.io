import math, time


class Solution:
    def minFallingPathSum(self, grid: list[list[int]]) -> int:
        n = len(grid)
        dp = []
        ans = sum([grid[i][i] for i in range(n)])
        dp.append(grid[0])
        for i in range(1, n):
            temp = [100 * (i + 1) for x in range(n)]
            for j in range(n):
                for k in range(n):
                    if k == j:
                        continue
                    temp[j] = min(temp[j], dp[i - 1][k])
                temp[j] += grid[i][j]
                if i == n - 1:
                    ans = min(ans, temp[j])
            dp.append(temp)
        return ans
