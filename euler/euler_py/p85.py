import math

if __name__ == '__main__':
    testSize = 80
    grid = [[0 for _ in range(testSize)] for _ in range(testSize)]
    grid[1][1] = 1
    e = 2000000
    target = 2000000
    ret = 0
    for i in range(1, testSize):
        for j in range(1, testSize):
            if i == 1:
                grid[i][j] = math.comb(j, 2) + j
            elif j == 1:
                grid[i][j] = grid[1][i]
            else:
                grid[i][j] = grid[i][j - 1] + grid[1][i]
                grid[i][j] += (j - 1) * (math.comb(i, 2) + i)
            temp_e = math.fabs(grid[i][j] - target)
            if temp_e < e:
                e = temp_e
                ret = i * j
    for i in range(1, 15):
        for j in range(1, 15):
            print(f'{grid[i][j]}, ',end='')
        print()
    print(ret)
