import heapq
import collections
import bisect


class Solution:
    def maxTaskAssign(self, tasks, workers, pills, strength):
        def satisfy(k):
            p = pills
            k_tasks = tasks[:k]
            k_workers = workers[len(workers) - k :]
            for j in range(k - 1, -1, -1):
                if k_tasks[j] <= k_workers[-1]:
                    k_workers.pop()
                else:
                    if p == 0:
                        return False
                    i = bisect.bisect_left(k_workers, k_tasks[j] - strength)
                    if i == len(k_workers):
                        return False
                    p -= 1
                    k_workers.pop(i)
            return True

        workers = sorted(workers)
        tasks = sorted(tasks)
        if len(workers) > len(tasks):
            workers = workers[len(workers) - len(tasks) :]
        print(f"tasks:{tasks}, workers: {workers}")
        left, right = 0, len(workers)
        while left <= right:
            mid = (left + right) // 2
            if satisfy(mid):
                left = mid + 1
            else:
                right = mid - 1
        return left - 1

    def maxTaskAssign1(self, tasks, workers, pills, strength):
        workers_cnt = collections.Counter(workers)
        tasks = sorted(tasks)
        tasks_cnt = collections.Counter(tasks)
        finished = [False] * len(tasks)
        arrangements = []
        # remain = len(workers)
        for worker in workers_cnt.elements():
            # print(one)
            for i, task in enumerate(tasks):
                if not finished[i]:
                    heapq.heappush(arrangements, (task - worker, task, worker))
                    workers_cnt[worker] -= 1
                    finished[i] = True
        while len(arrangements) < workers:
            # adjust them
            pass

    def maxTaskAssign2(self, tasks, workers, pills, strength):
        workers = sorted(workers)
        tasks = sorted(tasks)
        print(f"workers: {workers}, tasks: {tasks}")
        task_cnt = len(tasks)
        finished = [False] * task_cnt
        ans = 0
        # no pill first
        for i, worker in enumerate(workers):
            if worker in tasks:
                idx = tasks.index(worker)
                if not finished[idx]:
                    workers.pop(i)
                    finished[idx] = True
                    ans += 1

        for worker in workers:
            for i, task in enumerate(tasks):
                if finished[i]:
                    continue
                if worker >= task:
                    finished[i] = True
                    ans += 1
                elif worker + strength >= task and pills > 0:
                    finished[i] = True
                    pills -= 1
                    ans += 1
        return ans


if __name__ == "__main__":
    tasks = [3, 2, 1]
    workers = [0, 3, 3]
    s = Solution()
    print(s.maxTaskAssign(tasks, workers, 1, 1))
