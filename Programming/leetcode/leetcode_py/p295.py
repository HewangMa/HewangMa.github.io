class MedianFinder1:

    def insertion_sort(self):
        arr = self.nums
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key

    def __init__(self):
        self.nums = []
        self.sorted = False

    def addNum(self, num: int) -> None:
        self.nums.append(num)
        self.sorted = False

    def findMedian(self) -> float:
        if not self.sorted:
            self.insertion_sort()
            self.sorted = True
        if len(self.nums) % 2 == 0:
            one = self.nums[len(self.nums) // 2]
            two = self.nums[len(self.nums) // 2 - 1]
            return (one + two) / 2
        else:
            return self.nums[len(self.nums) // 2]


class MedianFinder:

    def __init__(self):
        self.st1 = []
        self.st2 = []

    def addNum(self, num: int) -> None:
        while self.st1 and self.st1[-1] > num:
            self.st2.append(self.st1.pop())
        while self.st2 and self.st2[-1] < num:
            self.st1.append(self.st2.pop())
        self.st1.append(num)

    def findMedian(self) -> float:
        n = len(self.st1) + len(self.st2)
        if len(self.st1) == len(self.st2):
            return (self.st1[-1] + self.st2[-1]) / 2
        else:
            long_one = self.st1 if len(self.st1) > len(self.st2) else self.st2
            # [1,2,3,4,5, 5.5]
            # [12,8,6]
            if n % 2 == 0:
                one = long_one[n // 2]
                two = long_one[n // 2 - 1]
                return (one + two) / 2
            else:
                return long_one[n // 2]


if __name__ == "__main__":
    m = MedianFinder()
    m.addNum(12)
    print(f"st1: {m.st1}, st2: {m.st2}")
    m.addNum(3)
    print(f"st1: {m.st1}, st2: {m.st2}")
    m.addNum(113)
    print(f"st1: {m.st1}, st2: {m.st2}")
    m.addNum(33)
    print(f"st1: {m.st1}, st2: {m.st2}")
    m.addNum(43)
    print(f"st1: {m.st1}, st2: {m.st2}")
