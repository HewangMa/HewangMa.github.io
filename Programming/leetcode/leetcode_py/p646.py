import copy


class Solution:
    def findLongestChain(self, pairs):
        pairs = sorted(pairs, key=lambda x: x[1])
        n = len(pairs)
        # try to find the final chain?
        # dp[i] = l, pairs represent the longest chain length and chain index ends with pairs[i]
        dp = [[1, [i]] for i in range(n)]
        max_length = 1
        res_i = 0
        for i in range(1, n):
            # use pre_idx to avoid copying too much
            pre_idx = -1
            for j in range(i):
                pre_chain_last_idx = dp[j][1][-1]
                if pairs[pre_chain_last_idx][1] < pairs[i][0]:
                    pre_len = dp[j][0]
                    # found pre_chain that may satisfy, look into their length
                    if pre_len + 1 > dp[i][0]:
                        dp[i][0] = pre_len + 1
                        pre_idx = j
            if pre_idx != -1:
                dp[i][1] = copy.deepcopy(dp[pre_idx][1])
            if dp[i][1][-1] != i:
                dp[i][1].append(i)
            if dp[i][0] > max_length:
                max_length = dp[i][0]
                res_i = i
        print(f"Found longest length:{max_length}, which is {dp[res_i][1]}")
        return max_length, dp[res_i][1]
