def runscript(points0, points1, points2, points3, points4):

    points = [points0, points1, points2, points3, points4]
    most_left = points[0][0][0]
    most_right = points[0][-1][0]
    print(most_left)
    print(most_right)

    index = [0, 0, 0, 0, 0]  # 记录每组正在访问的下标

    for domainLeft in range(most_left, most_right, 2):
        adjustment = [0, 0, 0, 0, 0]  # 记录每次要调整的index
        for i in range(5):
            while points[i][index[i]][0] < domainLeft:  # 当前下标还不到domainLeft
                index[i] += 1
            if points[i][index[i]][0] < domainLeft + 2:  # 当前下标需要调整
                adjustment[i] = index[i]

        maxheight = 0
        for i in range(5):
            if adjustment[i] == 0:
                continue
            if points[i][adjustment[i]][1] < maxheight:
                points[i][adjustment[i]] = (0, 0, 0)
            maxheight = max(maxheight, points[i][adjustment[i]][1])

    result0 = points[0]
    result1 = points[1]
    result2 = points[2]
    result3 = points[3]
    result4 = points[4]

    return result0, result1, result2, result3, result4

def test():
    pointsList4 = [(0, 0, 0), (2, 3, 0), (4, 5, 0), (6, 4, 0), (8, 8, 0), (10, 32, 0), (12, 13, 0)]
    pointsList3 = [(0, 0, 0), (2, 3, 0), (4, 9, 0), (6, 16, 0), (8, 8, 0), (10, 3, 0), (12, 9, 0)]
    pointsList2 = [(0, 0, 0), (2, 3, 0), (5, 90, 0), (6, 14, 0), (8, 18, 0), (9, 2, 0), (12, 4, 0)]
    pointsList1 = [(0, 0, 0), (2, 9, 0), (4, 8, 0), (6, 6, 0), (8, 10, 0), (10, 42, 0), (12, 6, 0)]
    pointsList0 = [(0, 0, 0), (1, 3, 0), (5, 5, 0), (6, 4, 0), (8, 8, 0), (11, 32, 0), (12, 4, 0)]
    prints = runscript(pointsList0, pointsList1, pointsList2, pointsList3, pointsList4)
    print(prints[4])
    print(prints[3])
    print(prints[2])
    print(prints[1])
    print(prints[0])

# if __name__ == '__main__':