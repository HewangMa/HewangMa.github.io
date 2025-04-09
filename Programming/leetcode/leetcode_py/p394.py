import collections


class Solution:
    def extract_num(self, s, i=0):
        ret = ""
        while "0" <= s[i] <= "9":
            ret += s[i]
            i += 1
        return ret

    def decodeString(self, s):
        st = []
        i = 0
        while i < len(s):
            if "0" <= s[i] <= "9":
                num = self.extract_num(s, i)
                i += len(num)
                st.append(num)
                print(num, end=", ")
            elif s[i] == "]":
                sub = ""
                while st[-1] != "[":
                    sub += st[-1][::-1]
                    st.pop()
                st.pop()
                sub = sub[::-1]
                print(sub)
                num = int(st.pop())
                st.append(sub * num)
                i += 1
            else:
                st.append(s[i])
                i += 1
        return "".join(st)


if __name__ == "__main__":
    s = Solution()
    code = "3[z]2[yypq4[2[jk]e1[f]]]ef"
    print(s.decodeString(code))
