import heapq


class Solution:
    def numberOfWeeks(self, milestones):
        n = len(milestones)
        if n < 2:
            return 1
        # big head heap
        h = []
        for m in milestones:
            heapq.heappush(h, -m)
        ret = 0
        while len(h) >= 1:
            print(h)
            if len(h) == 1:
                one = -heapq.heappop(h)
                ret += 1
            else:
                one = -heapq.heappop(h)
                two = -heapq.heappop(h)
                if two == 1:
                    step = 1
                else:
                    step = two // 2
                ret += 2 * step
                one -= step
                two -= step
                if one > 0:
                    heapq.heappush(h, -one)
                if two > 0:
                    heapq.heappush(h, -two)
        return ret


if __name__ == "__main__":
    milestones = [4, 5, 5, 2]
    s = Solution()
    print(s.numberOfWeeks(milestones))
