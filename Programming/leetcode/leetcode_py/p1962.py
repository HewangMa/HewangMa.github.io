import heapq


class Solution:

    def minStoneSum(self, piles, k):
        heap = []
        for p in piles:
            heapq.heappush(heap, (-p // 2, p % 2, p))
        while k > 0:
            k -= 1
            p = heap[0][2]
            heapq.heappop(heap)
            p = p - p // 2
            heapq.heappush(heap, (-p // 2, p % 2, p))
            # print(heap)
        ret = sum(one[2] for one in heap)
        return ret


if __name__ == "__main__":
    s = Solution()
    print(s.minStoneSum([4, 3, 6, 7], 3))
