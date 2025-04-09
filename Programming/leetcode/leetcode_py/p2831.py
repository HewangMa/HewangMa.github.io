class Solution:
    def find_longest(self, pos, k):
        i = 0
        j = 0
        n = len(pos)
        # print(f"pos: {pos}")
        ret = 0
        while j < n:
            curr_len = j - i + 1
            ret = max(ret, curr_len)
            j += 1
            while j < n and pos[j] - pos[i] - (j - i) > k:
                i += 1
        return ret

    def longestEqualSubarray(self, nums, k):
        poss = {}
        for i, num in enumerate(nums):
            if num not in poss:
                poss[num] = [i]
            else:
                poss[num].append(i)
        # 可以删除k个，那么可以使用滑动窗口确定在i，j之间有多少个pos
        ret = 0
        for num, pos in poss.items():
            len_num = self.find_longest(pos, k)
            ret = max(ret, len_num)
            # print(f"For {num}, find {len_num}")
        return ret


if __name__ == "__main__":
    s = Solution()
    print(s.longestEqualSubarray([1, 1, 2, 2, 1, 1], 2))
