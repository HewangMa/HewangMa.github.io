import heapq
from functools import cmp_to_key


class Solution:
    class task:
        def __init__(self, diff, profit) -> None:
            self.d = diff
            self.p = profit

        def __str__(self) -> str:
            return f"d={self.d}, p={self.p}"

    def cmp(self, a, b):
        if a.d == b.d:
            return b.p - a.p
        return b.d - a.d

    def cmp2(self, a, b):
        if a.p == b.p:
            return a.d - b.d
        return b.p - a.p

    def maxProfitAssignment0(self, difficulty, profit, worker):
        workers = sorted(worker, key=lambda x: -x)
        worker_cnt = len(worker)
        # 对于每个worker 给他能完成的profit最大的task
        # 将task按照diff升序，diff相同的按照profit降序排列
        n = len(difficulty)
        tasks = [self.task(difficulty[i], profit[i]) for i in range(n)]
        tasks = sorted(tasks, key=cmp_to_key(self.cmp2))
        return 0

    def maxProfitAssignment1(self, difficulty, profit, worker):
        worker = sorted(worker, key=lambda x: -x)
        n = len(difficulty)
        tasks = [self.task(difficulty[i], profit[i]) for i in range(n)]
        tasks = sorted(tasks, key=cmp_to_key(self.cmp2))
        for t in tasks:
            print(t)
        arrange = [0 for _ in worker]
        for t in tasks:
            for i, a in enumerate(arrange):
                if a == 0 and worker[i] >= t.d:
                    arrange[i] = max(arrange[i], t.p)
        print(arrange)
        return sum(arrange)

    def maxProfitAssignment(self, difficulty, profit, worker):
        # 递增单调栈，同时保存栈中最大profit
        worker = sorted(worker, key=lambda x: x)
        n = len(difficulty)
        tasks = [self.task(difficulty[i], profit[i]) for i in range(n)]
        tasks = sorted(tasks, key=lambda t: t.d)
        i = 0
        curr_max_p = 0
        ret=0
        for w in worker:
            while i < n and tasks[i].d <= w:
                curr_max_p = max(curr_max_p, tasks[i].p)
                i += 1
            ret += curr_max_p
        return ret


if __name__ == "__main__":
    diff = [4, 4, 6, 8, 10]
    profit = [10, 20, 30, 40, 50]
    worker = [4, 5, 6, 7]
    s = Solution()
    print(s.maxProfitAssignment(diff, profit, worker))
