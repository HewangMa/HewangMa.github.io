import math


class Chain:
    def __init__(self):
        self.testSize = 10000000
        Range = max(self.testSize + 1, 81 * int(math.log10(self.testSize)) + 90)
        self.tag = [-1 for _ in range(Range)]
        self.tag[1] = 0
        self.tag[89] = 1
        self.Q = []
        for i in range(1, self.testSize + 1):
            self.chain(i)
            self.Q.clear()
        print(sum(self.tag[1:self.testSize]))

    def chain(self, n):
        # print(f'trying {n}:')
        self.Q.append(n)
        if self.tag[n] != -1: return
        t = 0
        while n > 0:
            t += (n % 10) ** 2
            n //= 10
        if self.tag[t] != -1:
            for item in self.Q:
                self.tag[item] = self.tag[t]
            return
        else:
            self.chain(t)


if __name__ == '__main__':
    chain = Chain()
