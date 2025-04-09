class Solution:
    def can_get(self, x, y):
        ret = set()
        for i in [0, x, y, x + y]:
            ret.add(i)
        if x < y:
            t = x
            x = y
            y = t
        rest = 0
        while True:
            t = x - rest
            while t > y:
                t -= y
                ret.add(t)
            rest = y - t
            if rest == 0:
                break
            ret.add(x - rest)
            ret.add(x + rest)
        for i in ret:
            print(i)
        return ret

    def canMeasureWater(self, x, y, target):
        can_get = self.can_get(x, y)
        return target in can_get


if __name__ == "__main__":
    s = Solution()
    print(s.canMeasureWater(34, 5, 6))
