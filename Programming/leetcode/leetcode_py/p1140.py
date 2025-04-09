class Solution:
    # 害，就这样吧
    def res(self, piles, M):
        # 先手者在piles中能获得的最大石子数
        n = len(piles)
        if 2 * M >= n:
            return sum(piles)
        for x in range(1, 2 * M + 1):
            pass

    def stoneGameII(self, piles):
        n = len(piles)
        M = 1
