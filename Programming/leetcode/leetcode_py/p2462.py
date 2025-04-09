import heapq


class Solution:
    def totalCost(self, costs, k, candidates):
        total_cost = 0
        heap = []
        n = len(costs)
        left_bound = 0
        right_bound = n - 1
        while left_bound < candidates and left_bound <= right_bound:
            heapq.heappush(heap, (costs[left_bound], left_bound))
            left_bound += 1
        while right_bound >= n - candidates and right_bound >= left_bound:
            heapq.heappush(heap, (costs[right_bound], right_bound))
            right_bound -= 1
        print(heap)

        for _ in range(k):
            cost = heap[0][0]
            idx = heap[0][1]
            heapq.heappop(heap)
            total_cost += cost
            if idx < left_bound <= right_bound:
                heapq.heappush(heap, (costs[left_bound], left_bound))
                left_bound += 1
            elif right_bound >= left_bound:
                heapq.heappush(heap, (costs[right_bound], right_bound))
                right_bound -= 1
            print(f"After added ({cost},{idx}), heap is {heap}\n")

        return total_cost


if __name__ == "__main__":
    costs = [
        18,
        64,
        12,
        21,
        21,
        78,
        36,
        58,
        88,
        58,
        99,
        26,
        92,
        91,
        53,
        10,
        24,
        25,
        20,
        92,
        73,
        63,
        51,
        65,
        87,
        6,
        17,
        32,
        14,
        42,
        46,
        65,
        43,
        9,
        75,
    ]
    s = Solution()
    print(s.totalCost(costs, 13, 23))
