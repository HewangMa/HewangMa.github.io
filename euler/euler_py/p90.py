import math


class TrackBack:
    def __init__(self):
        self.st = []
        self.arr_list = []
        self.trackback()

    def trackback(self):
        self._trackback(0)

    def _trackback(self, startIndex):
        if len(self.arr_list) == 6:
            self.st.append(self.arr_list.copy())
            return
        for i in range(startIndex, 10):
            self.arr_list.append(i)
            self._trackback(i + 1)
            self.arr_list.pop()


# 01
# 04
# 09
# 16
# 25
# 36
# 49
# 64
# 81

digits_must = [0, 1, 4, 2, 5, 8, 3]


def valid(arr1, arr2):
    # : strict with the logic!

    # contain enough digits
    for d in digits_must:
        level = (d in arr1 or d in arr2)
        if not level: return False
    level = 6 in arr1 or 6 in arr2 or 9 in arr1 or 9 in arr2
    if not level: return False

    # 01
    if 0 in arr1:
        level = 0 in arr2 or 1 in arr2
        if not level: return False
    else:
        level = 1 in arr1
        if not level: return False

    # 04
    if 0 in arr1:
        level = 0 in arr2 or 4 in arr2
        if not level: return False
    else:
        level = 4 in arr1
        if not level: return False

    # 09
    if 0 in arr1:
        level = 0 in arr2 or 6 in arr2 or 9 in arr2
        if not level: return False
    else:
        level = 6 in arr1 or 9 in arr1
        if not level: return False

    # 16
    if 1 in arr1:
        level = 1 in arr2 or 6 in arr2 or 9 in arr2
        if not level: return False
    else:
        level = 6 in arr1 or 9 in arr1
        if not level: return False

    # 25
    if 2 in arr1:
        level = 2 in arr2 or 5 in arr2
        if not level: return False
    else:
        level = 5 in arr1
        if not level: return False

    # 36
    if 3 in arr1:
        level = 6 in arr2 or 9 in arr2 or 3 in arr2
        if not level: return False
    else:
        level = 6 in arr1 or 9 in arr1
        if not level: return False

    # 49
    if 4 in arr1:
        level = 6 in arr2 or 9 in arr2 or 4 in arr2
        if not level: return False
    else:
        level = 6 in arr1 or 9 in arr1
        if not level: return False

    # 64
    if 4 in arr1:
        level = 6 in arr2 or 9 in arr2 or 4 in arr2
        if not level: return False
    else:
        level = 6 in arr1 or 9 in arr1
        if not level: return False

    # 81
    if 1 in arr1:
        level = 8 in arr2 or 1 in arr2
        if not level: return False
    else:
        level = 8 in arr1
        if not level: return False

    return True


if __name__ == '__main__':
    tb = TrackBack()
    n = len(tb.st)
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            # print(tb.st[j], end='')
            # input()
            if valid(tb.st[i], tb.st[j]):
                print(tb.st[i], tb.st[j])
                ans += 1
    print(ans)
    # print(math.comb(10, 6))
