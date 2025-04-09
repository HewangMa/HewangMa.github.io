import math
class Solution:
    def findIndices(self, nums, indexDifference, valueDifference) :
        n=len(nums)
        for i in range(n):
            for j in range(n):
                if math.fabs(i-j)>=indexDifference and math.fabs(nums[i]-nums[j])>=valueDifference:
                    return [i,j]
        return [-1,-1]