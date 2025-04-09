from itertools import combinations, islice


def pairwiseCompare(x, y):
    return sum((1 if x1 > y1 else 0) for x1, y1 in zip(x, y))


def valid(list):
    n = len(list)
    cnt = 0
    for size in range(2, n // 2 + 1):
        combs1 = combinations(list, size)
        for i, c1 in enumerate(combs1):
            combs2 = combinations(list, size)
            combs2 = islice(combs2, i + 1, None)
            comb_items2 = [item for item in combs2 if not any(i in c1 for i in item)]
            for c2 in comb_items2:
                if pairwiseCompare(c1, c2):
                    cnt += 1
    print(cnt)
    return True


def choose(s, i):
    if not i:
        yield []
    else:
        for j in range(len(s) - i + 1):
            a, rest = [s[j]], s[j + 1:]
            for ss in choose(rest, i - 1):
                yield a + ss


if __name__ == '__main__':
    list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    valid(list)
