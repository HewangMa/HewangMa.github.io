import bisect
import heapq


class Solution1:
    def findMaximizedCapital(
        self, k: int, w: int, profits: list[int], capital: list[int]
    ) -> int:
        # 实际上是背包问题
        # 选择了k个之后，max_profit 是固定的
        # 就是要验证w 是否大于capital
        n = len(profits)

        # dp = [
        #     [0] * (k + 1) for _ in range(n)
        # ]  # dp[i][j] 表示 在p[0..i]中 选择j个项目 所能获得的最大收益
        # # dp[i][0]=0
        # # dp[0][j]
        # for j in range(1, k + 1):
        #     dp[0][j] = profits[0] if w >= capital[0] else 0

        # for i in range(1, n):
        #     for j in range(1, k + 1):
        #         dp[i][j] = 0

        dp = [[0] * w for _ in range(n)]
        # dp[i][j] 表示当我有j的资本时，在p[0..i] 中所能获得的最大收益
        # dp[i][0] = ??


class Solution2:
    def findMaximizedCapital(
        self, k: int, w: int, profits: list[int], capital: list[int]
    ) -> int:
        heap = []
        p = []
        n = len(profits)
        ret = 0
        for i in range(n):
            p.append([profits[i], capital[i], False])
        p = sorted(p, key=lambda x: (x[1], -x[0]))
        for i in range(k):
            pos1 = bisect.bisect_right([x[1] for x in p], w) - 1
            # ???
            print(pos1)
        print(p)


class Solution:
    def findMaximizedCapital(
        self, k: int, w: int, profits: list[int], capital: list[int]
    ) -> int:
        ps = [[p, c] for p, c in zip(profits, capital)]
        ps = sorted(ps, key=lambda x: x[1])
        heap = []
        i = 0
        n = len(ps)
        for _ in range(k):
            while i < n:
                if ps[i][1] > w:
                    break
                heapq.heappush(heap, [-ps[i][0], ps[i][1]])
                i += 1
            if len(heap) <= 0:
                break
            choose_p = heapq.heappop(heap)
            w -= choose_p[0]
        return w


if __name__ == "__main__":
    s = Solution()
    print(s.findMaximizedCapital(1, 0, [1, 2, 3], [0, 1, 2]))
