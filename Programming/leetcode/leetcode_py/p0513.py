class Solution:
    def solve0(self, heights):
        n = len(heights)
        ret = 0
        for i in range(n):
            for j in range(i + 1, n):
                ret = max(ret, min(heights[i], heights[j]) * (j - i))
        return ret

    def solve(self, heights):
        n = len(heights)
        st = []
        ret = 0
        # 以i 为右端且高度为heights[i]
        for i in range(0, n):
            while st and heights[st[-1]] <= heights[i]:
                st.pop()
            if st:
                ret = max(ret, (i - st[0]) * heights[i])
                print(f"Hold between ({st[0]},{i}), got {(i - st[0]) * heights[i]}")
            st.append(i)
        st = []
        # 以i 为左端且高度为heights[i]
        for i in range(n - 1, -1, -1):
            while st and heights[st[-1]] <= heights[i]:
                st.pop()
            if st:
                ret = max(ret, (st[0] - i) * heights[i])
                print(f"Hold between ({st[0]},{i}), got {(st[0] - i) * heights[i]}")
            st.append(i)
        return ret


if __name__ == "__main__":
    s = Solution()
    print(s.solve([1, 2, 3, 4, 5, 6, 7]))
