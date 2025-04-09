class Solution:
    def maximumSwap(self, num):
        num_s = str(num)
        ret = num
        n = len(num_s)
        for d in range(9, 0, -1):
            big_char = str(d)
            big_pos = num_s.rfind(big_char)
            if big_pos == -1:
                continue
            small_pos = 0
            while small_pos < big_pos and int(num_s[small_pos]) >= d:
                small_pos += 1
            if small_pos >= n or small_pos == big_pos:
                continue
            small_char = num_s[small_pos]
            news = int(
                num_s[:small_pos]
                + big_char
                + num_s[small_pos + 1 : big_pos]
                + small_char
                + num_s[big_pos + 1 :]
            )
            # print(f" swap big pos : {big_pos}, small  {small_pos}, get: {news}")
            ret = max(ret, news)
        return ret


if __name__ == "__main__":
    n = 98368
    s = Solution()
    print(s.maximumSwap(n))
