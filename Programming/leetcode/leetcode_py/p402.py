class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        st = []
        remain = len(num) - k
        for d in num:
            while k and st and st[-1] > d:
                st.pop()
                k -= 1
            st.append(d)
        return "".join(st[:remain]).lstrip("0") or "0"


if __name__ == "__main__":
    num = "12345"
    s = Solution()
    print(s.removeKdigits(num, 2))
