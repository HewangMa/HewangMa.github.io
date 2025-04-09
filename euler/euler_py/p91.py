import math
import matplotlib.pyplot as plt

testSize = 50


def draw(x1, y1, x2, y2):
    # plt.scatter([x1, x2], [y1, y2], color='red', marked='o')
    plt.figure(figsize=(8, 8))
    plt.plot([0, x1], [0, y1])
    plt.plot([0, x2], [0, y2])
    plt.plot([x1, x2], [y1, y2])
    plt.xlim(0, testSize + 1)
    plt.ylim(0, testSize + 1)
    plt.show()


def solve1():
    ans = 0
    # set y2/x2 > y1/x1 to tell two points
    for x1 in range(1, testSize + 1):
        for y1 in range(testSize + 1):
            # the region is limited by one line and a part of circle
            x0 = x1 / 2
            y0 = y1 / 2
            r = math.sqrt(x0 ** 2 + y0 ** 2)
            if y1 == 0:
                # trivial
                for x2 in [0, x1]:
                    for y2 in range(1, testSize + 1):
                        # print(f'({x1},{y1}),({x2},{y2})')
                        # draw(x1, y1, x2, y2)
                        ans += 1
                # not trival
                for x2 in range(1, testSize):
                    for y2 in range(1, testSize):
                        if math.sqrt((x2 - x0) ** 2 + (y2 - y0) ** 2) == r:
                            # print(f'({x1},{y1}),({x2},{y2})')
                            # draw(x1, y1, x2, y2)
                            ans += 1
            else:
                k1 = y1 / x1
                k2 = -x1 / y1
                b = y1 - k2 * x1
                for x2 in range(testSize + 1):
                    for y2 in range(1, testSize + 1):
                        if not (x2 == 0 or y2 / x2 > y1 / x1): continue
                        if y2 == k2 * x2 + b or math.sqrt((x2 - x0) ** 2 + (y2 - y0) ** 2) == r:
                            # print(f'({x1},{y1}),({x2},{y2})')
                            # draw(x1, y1, x2, y2)
                            ans += 1
    print(ans)


def rightTriangle(x1, y1, x2, y2):
    a = x1 ** 2 + y1 ** 2
    b = x2 ** 2 + y2 ** 2
    c = (x1 - x2) ** 2 + (y1 - y2) ** 2
    if a == 0 or b == 0 or c == 0: return False
    # make c the biggest
    if a > c:
        t = c
        c = a
        a = t
    if b > c:
        t = c
        c = b
        b = t
    return c == a + b


def solve2():
    ans = 0
    for x1 in range(testSize + 1):
        for y1 in range(testSize + 1):
            for x2 in range(testSize + 1):
                for y2 in range(testSize + 1):
                    if rightTriangle(x1, y1, x2, y2):
                        ans += 1
    print(ans / 2)

if __name__ == '__main__':
    solve2()