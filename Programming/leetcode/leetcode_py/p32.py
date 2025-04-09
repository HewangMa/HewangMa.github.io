class Solution:
    def longestValidParentheses1(self, s):
        n = len(s)
        MR = 0x7FFFFFFF
        dp = [MR for _ in range(n)]
        # dp[i] = j represent that j is the farest pos to make a valid substr
        for i in range(1, n):
            if s[i] == "(":
                continue
            j = i - 1
            while j >= 0:
                print(f"For {i}, we tried {j}")
                if s[j] == "(":
                    dp[i] = min(dp[i], j)
                if s[j] == ")" and dp[j] != MR:
                    j = dp[j]
                    dp[i] = min(dp[i], j)
                j -= 1
        return dp

    def longestValidParentheses(self, s):
        n = len(s)
        st = [-1]
        ret = 0
        for i, c in enumerate(s):
            if c == "(":
                st.append(i)
            else:  # c == ')'
                st.pop()
                if not st:
                    st.append(i)
                else:
                    ret = max(ret, i - st[-1])
        return ret


if __name__ == "__main__":
    s = Solution()
    print(s.longestValidParentheses("()(())"))
