class Solution0:
    def __init__(self) -> None:
        self.curr_students = 0
        self.max_students = 0
        self.print_tag = False

    def valid(self, seats, i, j):
        if seats[i][j] != ".":
            return False
        m = len(seats[0])
        left_ok = True if (j == 0 or seats[i][j - 1] != "s") else False
        right_ok = True if (j == m - 1 or seats[i][j + 1] != "s") else False
        left_up_ok = True if (j == 0 or i == 0 or seats[i - 1][j - 1] != "s") else False
        right_up_ok = (
            True if (j == m - 1 or i == 0 or seats[i - 1][j + 1] != "s") else False
        )
        return left_ok and right_ok and left_up_ok and right_up_ok

    def track_back(self, seats, i, j):
        n = len(seats)
        m = len(seats[0])
        for ii in range(i, n):
            col_start = j if ii == i else 0
            for jj in range(col_start, m):
                if self.valid(seats, ii, jj):
                    seats[ii][jj] = "s"
                    self.curr_students += 1
                    self.max_students = max(self.max_students, self.curr_students)
                    if jj + 1 == m:
                        self.track_back(seats, ii + 1, 0)
                    else:
                        self.track_back(seats, ii, jj + 1)
                    self.curr_students -= 1
                    seats[ii][jj] = "."

    def maxStudents(self, seats):
        self.track_back(seats, 0, 0)
        return self.max_students


class Solution:
    def __init__(self) -> None:
        self.curr_students = 0
        self.max_students = 0
        self.print_tag = False

    def valid(self, seats, i, j):
        if seats[i][j] != ".":
            return False
        m = len(seats[0])
        left_ok = True if (j == 0 or seats[i][j - 1] != "s") else False
        right_ok = True if (j == m - 1 or seats[i][j + 1] != "s") else False
        left_up_ok = True if (j == 0 or i == 0 or seats[i - 1][j - 1] != "s") else False
        right_up_ok = (
            True if (j == m - 1 or i == 0 or seats[i - 1][j + 1] != "s") else False
        )
        return left_ok and right_ok and left_up_ok and right_up_ok

    def track_back(self, seats, i, j, num):
        n = len(seats)
        m = len(seats[0])
        for ii in range(i, n):
            col_start = j if ii == i else 0
            for jj in range(col_start, m):
                if self.valid(seats, ii, jj):
                    seats[ii][jj] = "s"
                    self.curr_students += 1
                    if self.curr_students >= num:
                        print(f"one solution for {num} students:")
                        for row in seats:
                            print(row)
                        print()
                        raise ValueError()
                    if jj + 1 == m:
                        self.track_back(seats, ii + 1, 0, num)
                    else:
                        self.track_back(seats, ii, jj + 1, num)
                    self.curr_students -= 1
                    seats[ii][jj] = "."

    def can_put(self, seats, num):
        try:
            self.track_back(seats, 0, 0, num)
        except ValueError:
            print(f"can put {num} students!")
            return True
        return False

    def maxStudents(self, seats):
        n = len(seats)
        m = len(seats[0])
        left, right = 0, n * m
        while left < right:
            mid = (left + right) // 2
            if self.can_put(seats, mid):
                left = mid
            else:
                right = mid - 1
        return left


if __name__ == "__main__":
    seats = [
        [".", ".", ".", ".", "#", ".", ".", "."],
        [".", ".", ".", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", ".", "#", "."],
        [".", ".", ".", ".", ".", ".", ".", "."],
        [".", ".", "#", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", ".", ".", "."],
        [".", ".", ".", "#", ".", ".", "#", "."],
    ]
    s = Solution()
    print(s.maxStudents(seats))
