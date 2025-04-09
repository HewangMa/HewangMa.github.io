import sys


# sys.setrecursionlimit(100000)


class SolveSudoku:
    def __init__(self, grid):
        self.grid = grid

    def next_pos(self, i, j):
        for ii in range(i, 9):
            if ii == i:
                for jj in range(j + 1, 9):
                    if self.grid[ii][jj] == '0': return ii, jj
            else:
                for jj in range(9):
                    if self.grid[ii][jj] == '0': return ii, jj
        return 9, 0

    def valid(self, i, j, n):
        pi = i // 3
        pj = j // 3
        for ii in range(9):
            if self.grid[ii][j] == n: return False
        for jj in range(9):
            if self.grid[i][jj] == n: return False
        for ii in range(3):
            for jj in range(3):
                if self.grid[pi * 3 + ii][pj * 3 + jj] == n: return False
        return True

    def track_back(self, i, j):
        try:
            self._track_back(i, j)
        except ValueError as e:
            print(e)
            return

    def _track_back(self, i, j):
        if i == 9:
            raise ValueError('solved')
        for n in range(1, 10):
            c = str(n)
            if self.valid(i, j, c):
                line = self.grid[i]
                new_line = line[:j] + c + line[j + 1:]
                self.grid[i] = new_line
                # print(f'tring {n} on ({i},{j})', end='')
                # input()
                nexti, nextj = self.next_pos(i, j)
                # print(f'({nexti},{nextj})',end='->')
                self._track_back(nexti, nextj)
                grid[i] = line
        # print()


if __name__ == '__main__':
    with open('0096_sudoku.txt', 'r') as file:
        grid = []
        ans = 0
        for i in range(501):
            line = file.readline().strip()
            if i == 0: continue
            if i % 10 == 0:
                # got the last grid
                # print(f'the no. {i % 10} , problem:')
                # for row in grid:
                #     print(row)
                # print(f'\n the solution: ')
                tb = SolveSudoku(grid)
                start_i, start_j = 0, 0
                if grid[start_i][start_j] != '0':
                    start_i, start_j = tb.next_pos(start_i, start_j)
                tb.track_back(start_i, start_j)
                ans += int(tb.grid[0][:3])
                # for row in tb.grid:
                #     print(row)
                # print(f'the current sum is {ans}')
                # input()
                # exit()
                grid.clear()
                continue
            grid.append(line)
    print(ans)
