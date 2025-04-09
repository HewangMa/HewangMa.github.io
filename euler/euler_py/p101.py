import numpy as np


def g_func(n):
    # return n ** 3
    return 1 - n + n ** 2 - n ** 3 + n ** 4 - n ** 5 + n ** 6 - n ** 7 + n ** 8 - n ** 9 + n ** 10


def cal_from_certis(cer, n):
    l = len(cer)
    ret = 0
    for i in range(l):
        ret += cer[i] * n ** (l - i - 1)
    return ret


def op(k):
    A = []
    B = []
    for i in range(1, k + 1):
        temp = []
        for exp in range(k - 1, -1, -1):
            temp.append(i ** exp)
        A.append(temp)
        B.append(g_func(i))
    AA = np.array(A)
    BB = np.array(B)
    cers = np.linalg.solve(AA, BB)
    ret = 0
    for i in range(len(cers)):
        ret += cers[i] * (k + 1) ** (k - i - 1)
    return ret


if __name__ == '__main__':
    ans = 0
    for k in range(1, 11):
        ans += op(k)
    print(ans)