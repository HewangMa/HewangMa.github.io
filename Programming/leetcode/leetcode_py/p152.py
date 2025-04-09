class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        dp = [[n, n] for n in nums]
        # dp[i] = (max, min) represent the max and min proc end with nums[i]
        ret = max(0, dp[0][0])
        for i in range(1, n):
            max_pre = dp[i - 1][0]
            min_pre = dp[i - 1][1]
            dp[i][0] = max(dp[i][0], max_pre * nums[i], min_pre * nums[i])
            dp[i][1] = min(dp[i][1], max_pre * nums[i], min_pre * nums[i])
            ret = max(ret, dp[i][0])
        return ret
