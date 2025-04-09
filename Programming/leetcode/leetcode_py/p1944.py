from collections import deque


class Solution:
    def canSeePersonsCount(self, heights: list[int]) -> list[int]:
        q = []
        ans = [0] * n
        n = len(heights)
        for i, x in enumerate(heights):
            while q and q[-1] <= x:
                ans[q.pop()] += 1
            if q:
                ans[q[-1]] += 1
            q.append(i)
        return ans


if __name__ == "__main__":
    s = Solution()
    ans = s.canSeePersonsCount([2])
