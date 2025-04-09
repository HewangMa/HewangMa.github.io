import itertools


class Solution:
    def minFallingPathSum(self, matrix):
        n = len(matrix)
        dp = [[0x7FFFFFFF] * n for _ in range(n)]
        for c in range(n):
            dp[0][c] = matrix[0][c]
        ans = sum(matrix[r][0] for r in range(n))
        for r, c in itertools.product(range(1, n), range(n)):
            m = matrix[r][c]
            if c == 0:
                dp[r][c] = min(dp[r][c], dp[r - 1][c] + m, dp[r - 1][c + 1] + m)
            elif c == n - 1:
                dp[r][c] = min(dp[r][c], dp[r - 1][c] + m, dp[r - 1][c - 1] + m)
            else:
                dp[r][c] = min(
                    dp[r][c],
                    dp[r - 1][c] + m,
                    dp[r - 1][c + 1] + m,
                    dp[r - 1][c - 1] + m,
                )
            if r == n - 1:
                ans = min(ans, dp[r][c])
        return ans
