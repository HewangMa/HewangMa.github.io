# from collections import
import heapq


class Solution:
    def magicTower(self, nums):
        if sum(nums) < 0:
            return -1
        h = []
        n = len(nums)
        ret = 0
        cur = 1
        for num in nums:
            if num < 0:
                heapq.heappush(h, num)
            if cur + num < 1:
                ret += 1
                cur -= h[0]
                heapq.heappop(h)
            cur+=num
        return ret