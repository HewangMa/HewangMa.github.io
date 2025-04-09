class Solution:
    def numOfBurgers(self, tomatoSlices, cheeseSlices):
        if tomatoSlices > cheeseSlices * 4 or tomatoSlices < cheeseSlices * 2:
            return []
        if tomatoSlices % 2 == 1:
            return []
        j = (tomatoSlices - cheeseSlices * 2) // 2
        s = cheeseSlices - j
        return [j, s]
