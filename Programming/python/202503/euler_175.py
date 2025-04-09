import time


class Solution_1:
    def __init__(self):
        self.len = 20
        self.range = 2**self.len + 1
        self.fs = [0 for _ in range(self.range)]
        self.ffs = [[] for _ in range(self.range)]
        self.exps = [0] * self.len
        self.exps_res = 0
        self.exp_sum = 0
        self.exp_max = 0

    def back_(self, start):
        if self.exps_res < self.range:
            if self.exp_sum != self.exp_max or 1 != self.exp_max:
                self.fs[self.exps_res] += 1
                # self.ffs[self.exps_res].append([_ for _ in self.exps])
        else:
            return
        for i in range(start, self.len):
            base = self.exps_res
            sum_base = self.exp_sum
            for cnt in range(1, 3):
                self.exp_max = max(self.exp_max, cnt)
                self.exps[i] = cnt
                self.exps_res = base + (2**i) * self.exps[i]
                self.exp_sum = sum_base + cnt
                self.back_(i + 1)
            self.exp_sum = sum_base
            self.exps_res = base
            self.exps[i] = 0
            self.exp_max = max(self.exps)


if __name__ == "__main__":
    solve = Solution_1()
    print(solve.range)
    solve.back_(0)

    # print(solve.fs)
    # for i in range(solve.len):
    #     left, right = 2**i, 2 ** (i + 1) + 1
    #     print(f"{left}-{right-1}: {solve.fs[left:right]}")
    # for i, row in enumerate(solve.ffs):
    #     print(i, row,solve.fs[i])

    p, q = 123456789, 987654321
    # p,q = 13,17
    for n in range(solve.range):
        if q * solve.fs[n] == p * solve.fs[n - 1]:
            # solve.fs[n] * 9 == solve.fs[n - 1]
            print(n)
