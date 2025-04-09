class Solution:
    def apples_from(self, half_len):
        line = (1 + half_len) * half_len // 2
        return line * (half_len * 8 + 4)

    def minimumPerimeter(self, neededApples):
        left, right = 0, 500000
        while left < right:
            mid = (left + right) // 2
            contains = self.apples_from(mid)
            if contains == neededApples:
                return mid * 8
            if contains < neededApples:
                left = mid + 1
            else:
                right = mid - 1
        return (left if self.apples_from(left) >= neededApples else left + 1) * 8


if __name__ == "__main__":
    s = Solution()
    print(s.minimumPerimeter(61))
