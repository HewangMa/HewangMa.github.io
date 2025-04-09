class Solution:
    def __init__(self) -> None:
        self.dic = {}

    def dec_three(self, n):
        cnt = 0
        while n > 0:
            if n % 3 == 0:
                n = n // 3
            elif n % 3 == 1:
                n -= 1
            else:
                if n % 2 == 0:
                    n //= 2
                else:
                    n -= 1
            cnt += 1
        return cnt

    def dec_two(self, n):
        cnt = 0
        while n > 0:
            if n % 3 == 0:
                n //= 3
            else:
                if n % 2 == 0:
                    n //= 2
                else:
                    n -= 1
            cnt += 1
        return cnt

    def minDays1(self, n):
        return min(self.dec_three(n), self.dec_two(n))

    def minDays(self, n):
        if n in self.dic:
            return self.dic[n]
        if n == 0:
            self.dic[0] = 0
            return 0
        if n == 1:
            self.dic[1] = 1
            return 1
        if n == 2 or n == 3:
            self.dic[n] = 2
            return 2

        if n % 6 == 0:
            dec_from_three = 1 + self.minDays(n // 3)
            dec_from_two = 1 + self.minDays(n // 2)
            self.dic[n] = min(dec_from_three, dec_from_two)
            return self.dic[n]

        if n % 6 == 1:
            dec_from_three = 2 + self.minDays((n - 1) // 3)
            dec_from_two = 2 + self.minDays((n - 1) // 2)
            self.dic[n] = min(dec_from_three, dec_from_two)
            return self.dic[n]

        if n % 6 == 2:
            dec_from_three = 3 + self.minDays((n - 2) // 3)
            dec_from_two = 1 + self.minDays(n // 2)
            self.dic[n] = min(dec_from_three, dec_from_two)
            return self.dic[n]

        if n % 6 == 3:
            dec_from_three = 1 + self.minDays(n // 3)
            dec_from_two = 2 + self.minDays((n - 1) // 2)
            self.dic[n] = min(dec_from_three, dec_from_two)
            return self.dic[n]

        if n % 6 == 4:
            dec_from_three = 2 + self.minDays((n - 1) // 3)
            dec_from_two = 1 + self.minDays(n // 2)
            self.dic[n] = min(dec_from_three, dec_from_two)
            return self.dic[n]

        if n % 6 == 5:
            dec_from_three = 3 + self.minDays((n - 2) // 3)
            dec_from_two = 2 + self.minDays((n - 1) // 2)
            self.dic[n] = min(dec_from_three, dec_from_two)
            return self.dic[n]


if __name__ == "__main__":
    s = Solution()
    print(s.minDays(861646638))
