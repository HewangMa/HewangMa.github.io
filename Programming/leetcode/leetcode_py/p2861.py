class Solution:
    def can_produce(self, n, budget, demand, stock, cost, target):
        for i in range(n):
            need = demand[i] * target
            if need <= stock[i]:
                continue
            else:
                spend = (need - stock[i]) * cost[i]
                budget -= spend
                if budget < 0:
                    return False
        return True

    def find_max_output(self, n, budget, demand, stock, cost):
        left = 0
        right = 10
        while self.can_produce(n, budget, demand, stock, cost, right):
            # print(right)
            right *= 2
        mid = (left + right) // 2
        while left <= right:
            # print(f"({left},{right})")
            mid = (left + right) // 2
            if self.can_produce(n, budget, demand, stock, cost, mid):
                left = mid + 1
            else:
                right = mid - 1
        return mid if self.can_produce(n, budget, demand, stock, cost, mid) else mid - 1

    def maxNumberOfAlloys(self, n, k, budget, composition, stock, cost):
        ret = 0
        for i in range(k):
            demand = composition[i]
            print(demand)
            ret = max(ret, self.find_max_output(n, budget, demand, stock, cost))
        return ret


if __name__ == "__main__":
    n = 3
    k = 2
    budget = 15
    composition = [[1, 1, 1], [1, 1, 10]]
    stock = [0, 0, 0]
    cost = [1, 2, 3]
    s = Solution()
    print(s.maxNumberOfAlloys(n, k, budget, composition, stock, cost))
