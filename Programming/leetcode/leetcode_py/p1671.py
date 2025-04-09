class Solution:
    def minimumMountainRemovals(self, nums):
        n = len(nums)
        left = [1 for _ in range(n)]
        # left[i] 表示以i为山峰的左边的最长长度，即最长递增子序列
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    left[i] = max(left[i], left[j] + 1)
        right = [1 for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(n - 1, i, -1):
                if nums[i] > nums[j]:
                    right[i] = max(right[i], right[j] + 1)
        max_length = 0
        for i in range(n):
            if left[i] > 1 and right[i] > 1:
                max_length = max(max_length, left[i] + right[i] - 1)
        return n - max_length
