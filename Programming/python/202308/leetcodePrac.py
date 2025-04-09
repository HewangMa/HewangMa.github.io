class Solution:

    def addStrings(self, num1: str, num2: str) -> str:
        l1, l2 = len(num1) - 1, len(num2) - 1
        ret: str = ""
        n1: int = 0
        n2: int = 0
        ca: int = 0
        while l1 >= 0 or l2 >= 0:
            if l1 >= 0:
                n1 = int(num1[l1])
            else:
                n1 = 0

            if l2 >= 0:
                n2 = int(num2[l2])
            else:
                n2 = 0
            l1 = l1 - 1
            l2 = l2 - 1
            sum: int = n1 + n2 + ca
            ca = sum // 10
            add = sum % 10
            ret += str(add)
        if ca > 0:
            ret += str(ca)
        return ret[::-1]

    def arrangeCoins(self, n: int) -> int:
        # n->(n+1)*n/2
        if n == 1:
            return 1
        left, right = 1, n
        while left <= right:
            mid = (left + right) >> 1
            temp: int = mid * (mid + 1) / 2
            if temp > n:
                right = mid - 1
            elif temp == n:
                return mid
            else:
                left = mid + 1
        return left - 1

    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        n = len(nums)
        mp: dict[int, int] = {}
        ret: list[int] = []
        for i in nums:
            if i in mp:
                mp[i] += 1
            else:
                mp[i] = 1
        for i in range(n):
            if i not in mp:
                ret.append(i)
        return ret


def testOrd():
    ch: str = "a"
    print(type(ch))
    print(type(ord(ch)))
    num: int = 2
    print(type(chr(num)))


def ques415():
    n1: str = "123"
    n2: str = "456"
    s = Solution()
    print(s.addStrings(n1, n2))


def ques441():
    s = Solution()
    print(s.arrangeCoins(1804289383))
