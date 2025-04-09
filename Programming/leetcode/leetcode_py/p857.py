from queue import Queue


class Solution:
    class worker:
        def __init__(self, q, w) -> None:
            self.q = q
            self.w = w
            self.r = w / q  # 每单位质量需要的价格

        def __str__(self) -> str:
            return f"q={self.q}, w={self.w}, r={self.r:0.4f}"

    def minCostToHireWorkers(self, quality, wage, k):
        n = len(quality)
        workers = [self.worker(quality[i], wage[i]) for i in range(n)]
        workers = sorted(workers, key=lambda x: x.r)
        # 每单位质量价格低的排在前面，优先考虑
        for one in workers:
            print(one)
        # 以right的工资为比例安排总价格
        dp = [[0x7FFFFFFF for j in range(k + 1)] for i in range(n)]
        # dp[i][j] 表示在workers[0..i] 中选择j个，并以workers[i]为结尾 所要的最小cost
        # i + 1 >= j
        curr_quality_sum = 0
        for i in range(n):
            curr_quality_sum += workers[i].q
            dp[i][0] = 0  # choose none
            dp[i][i + 1] = curr_quality_sum * workers[i].r  
            # choose all, global rate is the rate of the most expensive person
        curr_quality_sum = 0
        for i in range(1,n):
            curr_quality_sum+=workers[i].q
            for j in range(1,i+2):
                # how to choose ?
                # choose=
                dp[i][j]=min(dp[i])


def test():
    qualities = [
        [10, 20, 5],
        [3, 1, 10, 10, 1],
        [25, 68, 35, 62, 52, 57, 35, 83, 40, 51],
    ]
    wages = [
        [70, 50, 30],
        [4, 8, 2, 2, 7],
        [147, 97, 251, 129, 438, 443, 120, 366, 362, 343],
    ]
    ks = [2, 3, 6]
    anss = [105, 30.6667, 1979.31429]
    s = Solution()
    test_len = len(qualities)
    for i in range(test_len):
        gt = anss[i]
        test = s.minCostToHireWorkers(qualities[i], wages[i], ks[i])
        print(f"Should be {gt}, got {test}\n\n")


if __name__ == "__main__":
    test()
