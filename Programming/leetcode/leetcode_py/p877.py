class Solution:

    def res_one(self, piles, total):
        # 递归太复杂了
        # 计算能在piles中获得的最大石子数
        if len(piles) == 1:
            return piles[0]
        if len(piles) == 2:
            return max(piles[0], piles[1])
        left = total - self.res_one(piles[1:], total - piles[0])
        right = total - self.res_one(piles[:-1], total - piles[-1])
        return max(left, right)

    def res_two(self, piles, alice):
        # 这个函数写的多余了
        ret = [0, 0]
        if len(piles) == 1:
            ret[alice] = piles[0]
            return ret
        # alice=1 表示alice先手，0表示bob先手
        # ret[0] 返回在piles中，bob可以拿到的最多石子
        # ret[1] 返回在piles中，alice可以拿到的最多石子
        left_res = self.res_two(piles[1:], 1 - alice)
        right_res = self.res_two(piles[:-1], 1 - alice)
        if left_res[alice] + piles[0] > right_res[alice] + piles[-1]:
            ret[alice] = left_res[alice] + piles[0]
            ret[1 - alice] = left_res[1 - alice]
        else:
            ret[alice] = right_res[alice] + piles[-1]
            ret[1 - alice] = right_res[1 - alice]
        return ret

    def stoneGame(self, piles):
        n = len(piles)
        pre_sum = [0]
        for p in piles:
            pre_sum.append(pre_sum[-1] + p)
        pre_sum = pre_sum[1:]
        dp = [[0 for _ in range(n)] for _ in range(n)]
        # dp[i][j] 表明先手者能在piles[i:j+1]中最多获得多少石子 (i <= j)
        # dp[i][j] = sum(piles[i:j+1]) - min( dp[i][j-1], dp[i+1][j]) 从主对角线向右上计算
        # 公式是和res_one 一样的道理，只是用了记忆化搜索
        for i in range(n):
            dp[i][i] = piles[i]
        for k in range(1, n):
            for i in range(n):
                j = i + k
                if j >= n:
                    break
                pre = 0 if i == 0 else pre_sum[i - 1]
                dp[i][j] = pre_sum[j] - pre - min(dp[i + 1][j], dp[i][j - 1])
        alice = dp[0][n - 1]
        bob = pre_sum[-1] - alice
        return alice > bob


if __name__ == "__main__":
    s = Solution()
    print(s.stoneGame([5, 4, 3, 5]))
