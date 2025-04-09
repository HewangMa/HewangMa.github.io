import math

import numpy as np


def contains0(coor):
    x1, y1 = coor[0], coor[1]
    x2, y2 = coor[2] - x1, coor[3] - y1
    x3, y3 = coor[4] - x1, coor[5] - y1
    # line of p1 and p2:
    tag1 = -y1 - (y2 / x2) * (-x1)

    # line of p1 and p3;
    tag2 = -y1 - (y3 / x3) * (-x1)

    # line of p2 and p3:
    a = np.array([[x3, y3], [x2, y2]])
    b = np.array([100, 100])
    res = np.linalg.solve(a, b)
    print(res, 100)
    tag3 = res[0] * (-x1) + res[1] * (-y1) - 100
    print(tag1, tag2, tag3)
    return True


def contains(coor):
    # using angles
    x1, y1 = coor[0], coor[1]
    x2, y2 = coor[2], coor[3]
    x3, y3 = coor[4], coor[5]
    a1 = math.acos((x1 * x2 + y1 * y2) / math.sqrt(x1 * x1 + y1 * y1) / math.sqrt(x2 * x2 + y2 * y2))
    a2 = math.acos((x1 * x3 + y1 * y3) / math.sqrt(x1 * x1 + y1 * y1) / math.sqrt(x3 * x3 + y3 * y3))
    a3 = math.acos((x3 * x2 + y3 * y2) / math.sqrt(x3 * x3 + y3 * y3) / math.sqrt(x2 * x2 + y2 * y2))
    print(a1 + a2 + a3 - 2 * math.pi)
    return math.fabs(a1 + a2 + a3 - 2 * math.pi) < 1e-10


if __name__ == '__main__':
    cnt = 0
    with open('0102_triangles.txt', 'r') as file:
        line = file.readline().strip()
        while line:
            coordinates = list(map(int, line.split(',')))
            # print(coordinates)
            if contains(coordinates):
                cnt += 1
            line = file.readline().strip()
    print(cnt)
