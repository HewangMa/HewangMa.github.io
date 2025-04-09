import itertools


class Solution1:
    def s1_first(self, s1, s2, s3):
        # 思路绝佳，但是超时了
        if s1 == s3:
            return True
        for length in range(1, len(s1) + 1):
            if s3[:length] == s1[:length]:
                if self.s1_first(s2, s1[length:], s3[length:]):
                    return True
            else:
                break
        return False

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) - len(s1) - len(s2) != 0:
            return False
        return self.s1_first(s1, s2, s3) or self.s1_first(s2, s1, s3)


class Solution:

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1, l2, l3 = len(s1), len(s2), len(s3)
        if l3 - l1 - l2 != 0:
            return False
        dp = [[False] * (l2 + 1) for _ in range(l1 + 1)]
        dp[0][0] = True
        for i, j in itertools.product(range(l1 + 1), range(l2 + 1)):
            p = i + j - 1
            if i > 0 and s1[i - 1] == s3[p]:
                dp[i][j] = dp[i][j] or dp[i - 1][j]
            if j > 0 and s2[j - 1] == s3[p]:
                dp[i][j] = dp[i][j] or dp[i][j - 1]
        return dp[l1][l2]
