import itertools


class Solution:
    def cherryPickup(self, grid) -> int:
        n = len(grid)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        dp[0][0] = grid[0][0]
        reachable = [[0 for _ in range(n)] for _ in range(n)]
        reachable[0][0] = 1
        not_reachable = -n * n
        for j in range(1, n):
            if grid[0][j] == -1:
                dp[0][j] = not_reachable
                break
            else:
                dp[0][j] = dp[0][j - 1] + grid[0][j]
        for i in range(1, n):
            if grid[i][0] == -1:
                dp[i][0] = not_reachable
                break
            else:
                dp[i][0] = dp[i - 1][0] + grid[i][0]

        for i, j in itertools.product(range(1, n), range(1, n)):
            status = grid[i][j]
            if status == -1:
                dp[i][j] = not_reachable
                continue
            if dp[i - 1][j] == not_reachable and dp[i][j - 1] == not_reachable:
                dp[i][j] = not_reachable
            elif dp[i - 1][j] == not_reachable:
                if dp[i][j - 1] + status > dp[i][j]:
                    dp[i][j] = dp[i][j - 1] + status
                    grid[i][j] = 0
            elif grid[i][j - 1] == -1:
                if dp[i - 1][j] + status > dp[i][j]:
                    dp[i][j] = dp[i - 1][j] + status
                    grid[i][j] = 0
            else:
                # can not change grid now
                dp[i][j] = max(dp[i - 1][j] + status, dp[i][j - 1] + status)
        for row in dp:
            print(row)


if __name__ == "__main__":
    s = Solution()
    grid = [[0, 1, -1], [1, 0, -1], [1, 1, 1]]
    print("The grid:")
    for row in grid:
        print(row)
    s.cherryPickup(grid)
