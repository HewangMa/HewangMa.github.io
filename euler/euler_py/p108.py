import math
from itertools import combinations


class TrackBack:
    def __init__(self, facs):
        self.n = max(facs.keys())
        self.n *= self.n
        self.st = set()
        self.st.add(1)
        self.facs = facs
        self.f = self.getHash()
        self.trackBack(1)

    def getHash(self):
        for k in self.facs:
            yield k

    def trackBack(self, current):
        self.f = self.getHash()
        self._trackBack(1)

    def _trackBack(self, current):
        try:
            index = next(self.f)
            for exp in range(self.facs[index]):
                current *= index ** exp
                self._trackBack(current)
                current /= index ** exp
        except StopIteration:
            if current <= self.n:
                self.st.add(current)


def solutions(n):
    t = n
    i = 2
    res = 1
    facDict = dict()
    while i <= t:
        if t % i == 0:
            # print(type(facDict.keys()))
            # exit()
            facDict[i] = facDict[i] + 2 if i in facDict.keys() else 2
            t /= i
        else:
            i += 1
            if i > 1000: return 1
    # print(facDict)
    for k in facDict.keys():
        res *= (facDict[k] + 1)
    return res
    # tb = TrackBack(facDict)
    # print(f'using trackBack, for n = {n}, facs = {tb.st}')

    # facList = []
    # for k in facDict.keys():
    #     for i in range(facDict[k]):
    #         facList.append(k)
    # st = set()
    # st.add(1)
    # for size in range(1, len(facList)):
    #     combs = combinations(facList, size)
    #     for c in combs:
    #         fac = math.prod(c)
    #         if fac <= n:
    #             st.add(fac)
    # # print(f'using list, for n = {n}, facs = {st}')
    # # input()
    # return len(st), facList


if __name__ == '__main__':
    n = 4
    cur = 3
    j = 0
    while True:
        s = solutions(n)
        s = (s + 1) / 2
        if s == 1: j += 1
        if s >= cur:
            cur = s
            print(f'jumped {j} nunms, got better ans, for n = {n},s = {s}, facs = 0')
            # input()
            j = 0
        if s > 10000:
            break
        n += 1
