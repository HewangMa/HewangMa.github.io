class Solution:
    def minFlipsMonoIncr(self, s):
        n = len(s)
        cnt1 = sum(int(c) for c in s)
        cnt0 = n - cnt1
        curr0 = 0
        curr1 = 0
        ret = n
        for c in s:
            op = curr1 + cnt0 - curr0
            ret = min(ret, op)
            if c == "0":
                curr0 += 1
            else:
                curr1 += 1
        ret=min(ret,curr1 + cnt0 - curr0)
        return ret