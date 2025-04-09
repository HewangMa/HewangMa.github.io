import math, time


class Solution1:
    def prime_factors(self, nums: int) -> list[int]:
        ret = []
        for i in range(2, nums + 1):
            if nums % i == 0:
                ret.append(i)
            while nums % i == 0:
                nums //= i
        return ret

    def findValidSplit(self, nums: list[int]) -> int:
        # 将数组中每个数字都分解质因数放进二维数组中，然后使用区间覆盖的方法去除所有被覆盖的答案
        ansList = []
        for i in range(len(nums)):
            ansList.append(1)

        Factors = []
        cover = []

        out_break = True
        for i in nums:
            Factors.append(self.prime_factors(i))
            for x in Factors[-1]:
                for preindex in range(len(Factors) - 1):
                    if x in Factors[preindex]:
                        # cover.append([preindex,len(Factors)-1])
                        for i in range(preindex, len(Factors) - 1):
                            ansList[i] = 0
                        out_break = False
                        break
                if out_break == False:
                    break
            out_break = True
        for i in cover:
            print(i)
        print(ansList)
        for i in range(0, len(ansList) - 1):
            if ansList[i] == 1:
                return i
                break
        else:
            return -1


class Solution2:
    def __init__(self) -> None:
        self.n = 0
        self.forbidden_ranges = []
        self.ans = 0

    def prime(self, p):
        if p < 2:
            return False
        for i in range(2, int(math.sqrt(p)) + 1):
            if p % i == 0:
                return False
        return True

    def merge_ranges(self):
        # merge 对性能优化很小
        merged = []
        merged.append([self.forbidden_ranges[0][0], self.forbidden_ranges[0][1]])
        for left, right in self.forbidden_ranges:
            c_right = merged[-1][1]
            if left <= c_right:
                merged[-1][1] = max(c_right, right)
            else:
                merged.append([left, right])
        return merged

    def use_p_to_seperate(self, p, nums) -> list[tuple[int, int]]:
        left = 0
        while left < self.n and nums[left] % p != 0:
            left += 1
        right = self.n - 1
        while left <= right and nums[right] % p != 0:
            right -= 1
        if left >= right:
            return
        self.forbidden_ranges.append((left, right))

    def findValidSplit(self, nums: list[int]) -> int:
        self.n = len(nums)
        num_max = max(nums)
        s1 = time.time()
        for p in range(2, int(math.sqrt(num_max)) + 1):
            if self.prime(p):
                self.use_p_to_seperate(p, nums)
        s2 = time.time()
        print(f"s2-s1: {s2-s1} s")
        for p in nums:
            if self.prime(p):
                self.use_p_to_seperate(p, nums)
        s3 = time.time()
        print(f"s3-s2: {s3-s2}s")
        self.forbidden_ranges = sorted(self.forbidden_ranges, key=lambda x: x[0])

        for left, right in self.forbidden_ranges:
            if left <= self.ans < right:
                self.ans = right
        s4 = time.time()
        print(f"s4-s3: {s4-s3}s")

        return self.ans if self.ans != self.n - 1 else -1


class Solution:
    def findValidSplit(self, nums: list[int]) -> int:
        n = len(nums)
        left = {}  # left[p] 表示质数 p 首次出现的下标
        right = [-1 for _ in range(n)]  # right[i] 表示左端点为 i 的区间的右端点的最大值
        # 区间的概念在这里隐去了，只记录左右端点

        def f(p, i):
            # 质数p 在i的位置出现了
            if p in left:
                right[left[p]] = i
            else:
                left[p] = i

        for i, num in enumerate(nums):
            d = 2
            while d * d <= num:
                if num % d == 0:
                    f(d, i)
                while num % d == 0:
                    num //= d
                d += 1
            if num > 1:
                f(num, i)

        ret = 0
        for l, r in enumerate(right):
            if l > ret:
                return ret
            ret = max(ret, r)
        return -1


if __name__ == "__main__":
    nums0 = [1, 1]
    nums = [
        557663,
        280817,
        472963,
        156253,
        273349,
        884803,
        756869,
        763183,
        557663,
        964357,
        821411,
        887849,
        891133,
        453379,
        464279,
        574373,
        852749,
        15031,
        156253,
        360169,
        526159,
        410203,
        6101,
        954851,
        860599,
        802573,
        971693,
        279173,
        134243,
        187367,
        896953,
        665011,
        277747,
        439441,
        225683,
        555143,
        496303,
        290317,
        652033,
        713311,
        230107,
        770047,
        308323,
        319607,
        772907,
        627217,
        119311,
        922463,
        119311,
        641131,
        922463,
        404773,
        728417,
        948281,
        612373,
        857707,
        990589,
        12739,
        9127,
        857963,
        53113,
        956003,
        363397,
        768613,
        47981,
        466027,
        981569,
        41597,
        87149,
        55021,
        600883,
        111953,
        119083,
        471871,
        125641,
        922463,
        562577,
        269069,
        806999,
        981073,
        857707,
        831587,
        149351,
        996461,
        432457,
        10903,
        921091,
        119083,
        72671,
        843289,
        567323,
        317003,
        802129,
        612373,
    ]
    nums2 = [
        922423,
        154787,
        358109,
        126013,
        476681,
        859667,
        231827,
        31337,
        122509,
        4801,
        205493,
        783553,
        506591,
        716917,
        429283,
        153817,
        662647,
        593387,
        973823,
        659843,
        554189,
        305369,
        922423,
        520943,
        693859,
        905783,
        123787,
        797003,
        320533,
        187373,
        17609,
        140071,
        971521,
        591431,
        276113,
        145681,
        867067,
        376531,
        488309,
        402253,
        643859,
        206543,
        382631,
        497011,
        805933,
        67141,
        987631,
        761251,
        839,
        580079,
        102071,
        240701,
        66271,
        790219,
        521317,
        521317,
        265451,
        201493,
        969719,
        863521,
        892481,
        898181,
        968879,
        521317,
        248291,
        789407,
        75217,
        708527,
        45053,
        443873,
        521317,
        201493,
        265091,
        601903,
        62057,
        802421,
        618671,
        693871,
        521317,
        456091,
        770039,
        859841,
        909409,
        644789,
        636569,
        351427,
        776599,
        491329,
        776507,
        881099,
        686911,
        717161,
        43609,
        696823,
        515377,
        534857,
        898427,
        201833,
        623341,
        585749,
        583789,
        206291,
        250993,
        734879,
        438913,
        823591,
        257903,
        670031,
        168127,
        296713,
        125383,
        809629,
        248057,
    ]

    s = Solution()
    print(s.findValidSplit(nums0))
