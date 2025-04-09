import math


class TrackBack:
    def __init__(self, k):
        self.ans_list = []
        self.current_prod = 1
        self.current_sum = 0
        self.trackback([], 1, k)

    def trackback(self, a_list, start_index, k):
        try:
            self._trackback(a_list, start_index, k)
        except ValueError as e:
            # print(e)
            self.current_prod = 1
            self.current_sum = 0
            return

    def _trackback(self, a_list, start_index, k):
        if len(a_list) == k:
            pos = -int(math.log2(2 * k)) - 1
            if pos >= -k and a_list[pos] == 2:
                raise ValueError(f"overflow with {a_list}")
            if self.current_prod == self.current_sum:
                # print(f'the max of a_list:{max(a_list)}')
                self.ans_list.append(self.current_prod)
                # print(f'put ans {a_list_sum} to ans_list')
                # print(a_list_sum)
            return
        for i in range(start_index, max(k // 3, 12)):
            if self.current_prod * i > k * k:
                return
            a_list.append(i)
            self.current_prod *= i
            self.current_sum += i
            # print(f'{a_list}, {self.current_prod}', end="")
            # input()
            self._trackback(a_list, i, k)
            # if math.prod(a_list) > k * k:
            #     # if self.current_prod > k * k:
            #     raise ValueError(f"prod overflow {a_list}")
            a_list.pop()
            self.current_prod /= i
            self.current_sum -= i


def tracebackSolve():
    testSize = 1200
    st = []
    for k in range(testSize - 3, testSize + 1):
        tb = TrackBack(k)
        k_min_N = min(tb.ans_list)
        # print(f'k: {k}, from {tb.ans_list}, result: {k_min_N}')
        if k_min_N not in st:
            st.append(k_min_N)
            print(len(st), k)
    print(sum(st))
    # print(f' all those of k with both cut:{st}')


class Split:
    def __init__(self, testSize):
        self.testSize = 12000
        self.minProdSum = [self.testSize * 2 + 2 for i in range(self.testSize + 1)]
        for i in range(2, self.testSize * 2 + 1):
            self.split(i, i, i, 0, 0)
        # self.calTheSum()

    def split(self, n, remain, maxFactor, sum, k):
        if remain == 1:
            k += n - sum
            if k <= self.testSize and n <= self.minProdSum[k]:
                self.minProdSum[k] = n
        else:
            for i in range(2, maxFactor + 1):
                if remain % i == 0:
                    self.split(n, remain / i, min(i, maxFactor), sum + i, k + 1)

    def calTheSum(self):
        st = set()
        for i in range(2, self.testSize + 1):
            st.add(self.minProdSum[i])
        return sum(st)


if __name__ == '__main__':
    sp = Split(12)
    print(sp.minProdSum)
    print(sp.calTheSum())
