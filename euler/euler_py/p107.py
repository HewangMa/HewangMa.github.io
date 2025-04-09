import sys

sys.setrecursionlimit(7000)


class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, t):
        if self.parent[t] != t:
            self.parent[t] = self.find(self.parent[t])
        return self.parent[t]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1


if __name__ == '__main__':
    weight = [[0 for _ in range(40)] for _ in range(40)]
    i = 0

    with open('0107_network.txt', 'r') as f:
        line = f.readline().strip()
        while line:
            items = line.split(',')
            for j, item in enumerate(items):
                if item == '-':
                    weight[i][j] = sys.maxsize
                else:
                    weight[i][j] = int(item)
            i += 1
            line = f.readline().strip()

    # for row in weight:
    #     print(row)
    edges = [(i, j, weight[i][j]) for i in range(40) for j in range(i, 40)]
    edges = sorted(edges, key=lambda x: x[2])
    uf = UnionFind(40)
    print(edges)
    cost = 0
    total_cost = 0
    for edge in edges:
        i, j, w = edge[0], edge[1], edge[2]
        # print(i,j,w)
        # exit()
        if w == sys.maxsize:
            break
        else:
            total_cost += w
        if uf.find(i) != uf.find(j):
            uf.union(i, j)
            cost += w
    ans = total_cost - cost
    print(ans)
    # print(uf.rank)
