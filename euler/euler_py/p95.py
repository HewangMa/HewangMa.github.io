import math
import sys

testSize = 1000000


def proper_divisors(n):
    ret = [1, ]
    sq = int(math.sqrt(n))
    for i in range(2, sq + 1):
        if n % i == 0:
            if i != n / i:
                ret.append(i)
                ret.append(int(n / i))
            else:
                ret.append(i)
    return ret


# 25, 6, 6

class logger:
    def log_print(self, s):
        with open('p95.log', 'a') as log_file:
            log_file.write(s + '\n')


def length_of_chain(n):
    chain = []
    while True:
        if n > testSize: return 0, 0
        if n in chain:
            ret = sys.maxsize
            for i in range(-1, -len(chain) - 1, -1):
                ret = min(ret, chain[i])
                if chain[i] == n:
                    return -i, ret
        else:
            chain.append(n)
        n = sum(proper_divisors(n))


if __name__ == '__main__':
    current_longest = 1
    ans = sys.maxsize
    for i in range(1, testSize + 1):
        l, min_of_chain = length_of_chain(i)
        if i % (testSize // 10) == 0: print(f'going on {i}')
        if l > current_longest:
            current_longest = l
            ans = min_of_chain
            print(f'find an ans: start from {i}, length is {l}, min of chain is {ans}')
    print(ans)
