class Solution:

    def findMin(self, nums: list[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low < high:
            mid = low + (high - low) // 2
            print(mid)
            if nums[mid] < nums[high]:
                high = mid
            else:
                low = mid + 1
        return nums[low]


if __name__ == "__main__":
    nums = [5, 6, 7, 8, 9, 1, 2, 3, 4]
    s = Solution()
    print(s.findMin(nums))


# * * * *
# * * * * *
# * * * * * *
# * * * * * * * *
# * *
# * * *
