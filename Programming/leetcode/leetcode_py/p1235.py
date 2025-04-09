import bisect


class Solution:
    class job:
        def __init__(self, s, e, p):
            self.s = s
            self.e = e
            self.p = p

        def __str__(self) -> str:
            return f"s={self.s}, e={self.e}, p={self.p};"

    def jobScheduling(self, startTime, endTime, profit):
        n = len(startTime)
        jobs = [self.job(startTime[i], endTime[i], profit[i]) for i in range(n)]
        jobs = sorted(jobs, key=lambda j: j.e)
        sorted_end_time = sorted(endTime)
        for j in jobs:
            print(j)

        # max_p[i] = p,e 表示在jobs[0..i] 中选择的最大profit 和 end time
        max_p = [[0, 0] for _ in range(n)]
        # initialize
        max_p[0][0], max_p[0][1] = jobs[0].p, jobs[0].e

        for j in range(1, n):
            job = jobs[j]
            # choose j
            ava_j = bisect.bisect_right(sorted_end_time, job.s)
            # print(f"If chose {j}, find ava_j at {ava_j}")
            if ava_j == 0:
                chose_p = job.p
            else:
                ava_j -= 1
                chose_p = job.p + max_p[ava_j][0]
            # not chose j
            not_chose_p = max_p[j - 1][0]
            if chose_p > not_chose_p:
                max_p[j][0] = chose_p
                chose_e = job.e
                max_p[j][1] = chose_e
            else:
                max_p[j][0] = not_chose_p
                not_chose_e = max_p[j - 1][1]
                max_p[j][1] = not_chose_e
        # print(f"The max_p: {max_p}")
        return max_p[n - 1][0]


if __name__ == "__main__":
    st = [6, 15, 7, 11, 1, 3, 16, 2]
    et = [19, 18, 19, 16, 10, 8, 19, 8]
    p = [2, 9, 1, 19, 5, 7, 3, 19]
    s = Solution()
    print(s.jobScheduling(st, et, p))
