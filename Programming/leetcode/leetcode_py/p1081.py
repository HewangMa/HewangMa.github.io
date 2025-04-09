class Solution:
    def smallestSubsequence(self, s: str) -> str:
        cnt = [s.count(chr(97 + i)) for i in range(26)]
        st = []
        for d in s:
            cnt[ord(d) - 97] -= 1
            if d in st:
                continue
            while st and st[-1] > d and cnt[ord(st[-1]) - 97] > 0:
                st.pop()
            st.append(d)
        return "".join(st)


if __name__ == "__main__":
    s = "cbaacabcaaccaacababa"
    solution = Solution()
    print(solution.smallestSubsequence(s))
