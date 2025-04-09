import itertools


class Solution:
    def minimumDeleteSum(self, s1, s2):
        s1 += " "
        s2 += " "
        n1, n2 = len(s1), len(s2)
        cp = [[0] * n2 for _ in range(n1)]
        # cp[i][j] represents largest common part's ascii value of
        # s1[0..i] s2[0..j]
        cp[0][0] = ord(s1[0]) if s1[0] == s2[0] else 0
        have_first_char = False
        total_sum = sum(ord(c) for c in s1) + sum(ord(c) for c in s2)
        for j in range(n2):
            if have_first_char:
                cp[0][j] = ord(s1[0]) * 2
            elif s2[j] == s1[0]:
                have_first_char = True
                cp[0][j] = ord(s1[0]) * 2
        have_first_char = False
        for i in range(n1):
            if have_first_char:
                cp[i][0] = ord(s2[0]) * 2
            elif s1[i] == s2[0]:
                have_first_char = True
                cp[i][0] = ord(s2[0]) * 2
        max_cp = 0
        for i, j in itertools.product(range(1, n1), range(1, n2)):
            if s2[j] == s1[i]:
                cp[i][j] = ord(s2[j]) * 2 + cp[i - 1][j - 1]
            else:
                cp[i][j] = max(cp[i - 1][j], cp[i][j - 1])
            max_cp = max(max_cp, cp[i][j])
        return total_sum - max_cp
