import sys

sys.set_int_max_str_digits(100000)


def valid(f):
    s = str(f)
    if len(s) < 17: return False
    cnts = [0 for _ in range(10)]
    for i in range(9):  # 0-8
        cnts[ord(s[i]) - ord('0')] += 1
    for i in range(1, 10):
        if cnts[i] != 1: return False

    cnts = [0 for _ in range(10)]
    for i in range(9):
        cnts[ord(s[-i - 1]) - ord('0')] += 1
    for i in range(1, 10):
        if cnts[i] != 1: return False
    return True


if __name__ == '__main__':
    f1, f2 = 1, 1
    # 1,1,2,3,5,8,13,21
    k = 3
    while True:
        f = f1 + f2
        if valid(f):
            print(f)
            print(k)
            break
        f1 = f2
        f2 = f
        k += 1
