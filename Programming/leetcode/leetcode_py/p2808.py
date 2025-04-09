class Solution:
    def find_step(self, nums_length, num, pos):
        # 已经有了所有的pos，只要找到最大间隔就可以
        n = len(pos)
        biggest_gap = 0
        for i, p in enumerate(pos):
            pre = pos[(i - 1 + n) % n]
            post = pos[(i + 1) % n]
            biggest_gap = max(
                biggest_gap,
                ((p - pre + nums_length) % nums_length) // 2,
                ((post - p + nums_length) % nums_length) // 2,
            )
        return biggest_gap

    def minimumSeconds(self, nums):
        # 每个值要蔓延到整个数组所需的最少步数
        # 假如m出现了两次，n出现了一次，那么必然选择m而不是n
        # 假如s出现了两次，t出现了三次，那么不一定选择谁
        n = len(nums)
        ret = n // 2  # 结果不会超过n//2次，这也是所有元素都出现一次的情况
        cnt = {}
        # cnt[num] = [appear_time,pos0,pos1...] pos递增
        for i, num in enumerate(nums):
            if num not in cnt:
                cnt[num] = [1, i]
            else:
                cnt[num][0] += 1
                cnt[num].append(i)
        for num in nums:
            if cnt[num][0] == 1:
                continue
            ret = min(ret, self.find_step(n, num, cnt[num][1:]))
        return ret