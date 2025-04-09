import math


def prime(n):
    if n <= 1: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True


def divisors(n):
    if n == 0: return []
    factors = [1, ]
    for i in range(2, n + 1):
        if n % i == 0: factors.append(i)
    return factors


def practical(n):
    divs = divisors(n)
    dp = [0 for _ in range(n + 1)]
    for div in divs:
        for j in range(n, -1, -1):
            if not j >= div: break
            dp[j] = max(dp[j], dp[j - div] + div)
    for i in range(n + 1):
        if dp[i] != i: return False
    return True
    # return True


if __name__ == '__main__':
    # print(divisors(12))
    # exit()
    n = 0
    cnt = 0
    # 0 none
    # 3 prime
    # 5 practical
    # 8 prime and practical
    tag = []
    # for i in range(21): print(i, end=', ')
    # print()
    tagSize = 40000
    while n < tagSize:
        tag.append(0)
        if n % 2 == 0:
            if practical(n):
                if n % 2048 == 0: print(f'find practical:{n}')
                tag[n] += 5
        else:
            if prime(n): tag[n] += 3
        n += 1
    n = 10
    print(f'finished tag of {tagSize}')
    while n + 9 < tagSize:
        if tag[n - 9] == tag[n - 3] == tag[n + 3] == tag[n + 9] == 3:
            if tag[n - 8] == tag[n - 4] == tag[n] == tag[n + 4] == tag[n + 8] == 5:
                print(f'find one: {n}')
        n += 2
        if n % 10002 == 0: print(f'testing on {n}')
