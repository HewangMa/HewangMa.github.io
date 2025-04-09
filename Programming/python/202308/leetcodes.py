from collections import Counter
import bisect


class Solution:
    dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    points = 0
    n = 0
    m = 0
    visited = []
    conn = False

    def valid(self, i: int, j: int) -> bool:
        if i >= 0 and i < self.n and j >= 0 and j < self.m:
            return True
        else:
            return False

    def dfs(self, grid: list[list[int]], i: int, j: int):
        self.visited[i][j] = 1
        # 四个方向都找一遍
        for k in range(4):
            ii = i + self.dir[k][0]
            jj = j + self.dir[k][1]
            while self.valid(ii, jj) and grid[ii][jj] == 0:
                ii += self.dir[k][0]
                jj += self.dir[k][1]
            if not self.valid(ii, jj): continue
            if grid[ii][jj] == 1 and self.visited[ii][jj] == 0:
                self.conn = True
                self.points += 1
                self.dfs(grid, ii, jj)

    def countServers(self, grid: list[list[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        self.visited = [[0 for j in range(self.m)] for i in range(self.n)]
        ans = 0
        for i in range(self.n):
            for j in range(self.m):
                if self.visited[i][j] == 0 and grid[i][j] == 1:
                    self.conn = False
                    self.points = 1
                    self.dfs(grid, i, j)
                    if self.conn: ans += self.points
        return ans

    def longestConsecutive1(self, nums: list[int]) -> int:
        uni = []
        [uni.append(x) for x in nums if x not in uni]
        uni.sort()
        n = len(uni)
        if n == 0:
            return 0
        l = 1
        ans = 1
        for i in range(n):
            if i > 0 and uni[i - 1] == uni[i] - 1:
                l += 1
                ans = max(ans, l)
            else:
                l = 1
        return ans

    def longestConsecutive2(self, nums: list[int]) -> int:
        # 尝试使用装有集合的集合来实现 但是失败了
        if len(nums) == 0:
            return 0
        sets = set()
        ans = 1
        for x in nums:
            put = False
            new_set = set()
            for sett in sets:
                if x + 1 in sett or x - 1 in sett:
                    put = True
                    sett.add(x)
                    new_set = new_set.union(sett)
                    sets.remove(sett)
            sets.add(new_set)
            ans = max(ans, len(new_set))
            if not put:
                sets.add({x})
        return ans

    def longestConsecutive(self, nums: list[int]) -> int:
        n = len(nums)
        if len(nums) == 0:
            return 0
        counted = Counter()
        cnt = Counter()
        for x in nums:
            cnt[x] += 1
        ans = 1
        for x in nums:
            if counted[x] == 1:
                continue
            counted[x] = 1
            p = x + 1
            q = x - 1
            while cnt[p] > 0:
                counted[p] = 1
                p += 1
            while cnt[q] > 0:
                counted[q] = 1
                q -= 1
            ans = max(ans, p - q - 1)
        return ans

    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        sum = nums[0] + nums[1] + nums[2]
        min_distance = abs(sum - target)
        n = len(nums)
        for i in range(0, len(nums)):
            one = nums[i]
            left = i + 1
            right = n - 1
            while left < right:
                two = nums[left]
                three = nums[right]
                dis = abs(one + two + three - target)
                if dis == 0:
                    return one + two + three
                if dis < min_distance:
                    sum = one + two + three
                    min_distance = dis
                if one + two + three > target:
                    right -= 1
                else:
                    left += 1
        return sum

    def generateParenthesis(self, n: int) -> list[str]:
        if n == 0:
            return []
        if n == 1:
            return ['()']
        ret = []
        for i in range(n):
            '''
            (a)b
            '''
            j = n - 1 - i
            l1 = self.generateParenthesis(i)
            l2 = self.generateParenthesis(j)
            # print(f'i:{i} l1:{l1}')
            # print(f'j:{j} l2:{l2}')
            if len(l2) == 0:
                [ret.append('(' + x + ')') for x in l1]
            if len(l1) == 0:
                [ret.append('()' + x) for x in l2]
            for s2 in l2:
                for s1 in l1:
                    ret.append('(' + s1 + ')' + s2)
        return ret

    def countAndSay(self, n: int) -> str:
        anss = ['1', '11', '21', '1211']  # 记录每个答案
        for i in range(3, n - 1):
            pre = anss[i]
            # 开始数pre放到ans中
            ans = ''
            numstr = pre[0]
            count = 1
            # 对pre进行连续段计算
            for j in range(1, len(pre)):
                # print(f'j:{j} pre[j]:{pre[j]}')
                if j > 0 and pre[j] == pre[j - 1]:
                    count += 1
                else:
                    # 放入并重置
                    ans = ans + str(count) + numstr
                    # print(ans)
                    numstr = pre[j]
                    count = 1
            ans = ans + str(count) + numstr
            print(f'pre:{pre} ans:{ans}')
            anss.append(ans)
            # print(anss)
        return anss[n - 1]


if __name__ == '__main__':
    ss = Solution()
    grid = [[1, 1, 0, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
    print(ss.countAndSay(5))
