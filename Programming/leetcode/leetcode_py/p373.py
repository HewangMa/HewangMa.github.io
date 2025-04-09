import heapq
import bisect


class Solution1:
    # unsolved
    def kSmallestPairs(self, nums1, nums2, k):
        ret = []
        heap = []
        for n1 in nums1:
            for n2 in nums2:
                heapq.heappush(heap, [-n1 - n2, n1, n2])
                if len(heap) > k:
                    heapq.heappop(heap)
        for one in heap:
            ret.append([one[1], one[2]])
        return ret


class Solution:
    # unsolved
    def kSmallestPairs(self, nums1, nums2, k):
        i, j = 0, 0
        ret = []
        n1, n2 = len(nums1), len(nums2)
        curr_low_bound = 0x80000000
        while len(ret) < k:
            ret.append([nums1[i], nums2[j]])
            curr_low_bound = max(curr_low_bound, sum(ret[-1]))
            if i == n1 - 1:
                j += 1
            if j == n2 - 1:
                i += 1

            if nums1[i + 1] + nums2[j] < nums1[i] + nums2[j + 1]:
                i += 1
                # 将j定位到刚好比cur大一点的位置
                j = bisect.bisect_left(nums2, curr_low_bound - nums1[i] + 1)
            else:
                j += 1
                i = bisect.bisect_left(nums1, curr_low_bound - nums2[j] + 1)
        return ret