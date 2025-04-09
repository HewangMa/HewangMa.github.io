import copy

# unsolved
class Solution0:
    def valid(self, s, i, j, dpc):
        odd_appear = 0
        for digit in range(10):
            pre = dpc[digit][i - 1] if i > 0 else 0
            if (dpc[digit][j] - pre) % 2 == 1:
                odd_appear += 1
                if odd_appear >= 2:
                    return False
        return True

    def longestAwesome(self, s):
        n = len(s)
        dp = [1 for _ in range(n + 1)]  # dp[i] 表示s[:i]中 以s[i]为结尾的最长超赞substr
        dp[0] = 0
        ret = 1
        dpc = [[0 for j in range(n)] for d in range(10)]
        for j in range(n):
            for d in range(10):
                dpc[d][j] = 0 if j == 0 else dpc[d][j - 1]
                if d == int(s[j]):
                    dpc[d][j] += 1
            for i in range(j + 1):
                if self.valid(s, i, j, dpc):
                    dp[j] = max(dp[j], j - i + 1)
            ret = max(ret, dp[j])
        # for row in dpc:
        #     print(row)
        return ret


class Solution:
    def earliest_pos(self, s, cnt):
        i = 0
        while sum(cnt) >= 2:
            pop = int(s[i])
            cnt[pop] = 1 - cnt[pop]
            i += 1
        return i

    def longestAwesome(self, s):
        n = len(s)
        cnt = [0 for _ in range(10)]
        ret = 0
        for j in range(n):
            d = int(s[j])
            cnt[d] = 1 - cnt[d]
            cal_cnt = copy.deepcopy(cnt)
            i = self.earliest_pos(s, cal_cnt)
            ret = max(ret, j - i + 1)
            # print(f"find {j-i+1} in s({i},{j})")
        return ret


if __name__ == "__main__":
    s = "3242415"
    solver = Solution()
    print(solver.longestAwesome(s))
