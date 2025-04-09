class Solution:

    def maxNumber(self, nums1, nums2, k):
        def pick(num, k):
            st = []
            drop = len(num) - k
            for d in num:
                while drop and st and st[-1] < d:
                    st.pop()
                    drop -= 1
                st.append(d)
            return st[:k]

        def merge(n1, n2):
            ret = []
            while n1 or n2:
                if n1 > n2:
                    ret.append(n1[0])
                    n1 = n1[1:]
                else:
                    ret.append(n2[0])
                    n2 = n2[1:]
            return ret

        ans = ""
        for k1 in range(k + 1):
            k2 = k - k1
            if not (0 <= k1 <= len(nums1) and 0 <= k2 <= len(nums2)):
                continue
            p1 = pick(nums1, k1)
            p2 = pick(nums2, k2)
            print(f"for ({k1},{k2}), got p1: {p1}, p2: {p2}")
            res = merge(p1, p2)
            res = "".join(str(i) for i in res)
            if res > ans:
                ans = res
        return [int(c) for c in ans]


class ref_Solution:
    def maxNumber(self, nums1, nums2, k):

        def pick_max(nums, k):
            stack = []
            drop = len(nums) - k
            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:k]

        def merge(A, B):
            ans = []
            while A or B:
                bigger = A if A > B else B
                ans.append(bigger.pop(0))
            return ans

        return max(
            merge(pick_max(nums1, i), pick_max(nums2, k - i))
            for i in range(k + 1)
            if i <= len(nums1) and k - i <= len(nums2)
        )


def run():
    n1 = [6, 7]
    n2 = [6, 0, 4]
    s = Solution()
    print(s.maxNumber(n1, n2, 5))


def test():
    l1 = []
    l2 = [1, 4, 3]
    print(l1 > l2)


if __name__ == "__main__":
    run()
