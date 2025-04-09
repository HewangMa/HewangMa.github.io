import bisect


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution0:
    def find_bound(self, root, goal):
        min_ = -1
        max_ = 1000009
        p = root
        while p and p.val != goal:
            if p.val > goal:
                max_ = min(max_, p.val)
                p = p.left
            else:
                min_ = max(min_, p.val)
                p = p.right
        if not p:
            return [min_, max_ if max_ != 1000009 else -1]
        return [p.val, p.val]

    def closestNodes(self, root, queries):
        # find the min and max val of tree first
        min_ = 1000009
        max_ = -1
        p = root
        while p:
            min_ = min(min_, p.val)
            p = p.left
        p = root
        while p:
            max_ = max(max_, p.val)
            p = p.right
        ret = []
        for goal in queries:
            if goal < min_:
                temp = [-1, min_]
            if goal > max_:
                temp = [max_, -1]
            if min_ <= goal <= max_:
                temp = self.find_bound(root, goal)
            ret.append(temp)
        return ret


class Solution(object):
    def __init__(self) -> None:
        self.vals = []

    def get_vals(self, root):
        if root:
            self.get_vals(root.left)
            self.vals.append(root.val)
            self.get_vals(root.right)

    def closestNodes(self, root, queries):
        self.get_vals(root)
        n = len(self.vals)
        ret = []
        for goal in queries:
            pos = bisect.bisect_left(self.vals, goal)

            if pos < n and self.vals[pos] == goal:
                temp = [goal, goal]
            elif pos >= n:
                temp = [self.vals[-1], -1]
            elif pos == 0:
                temp = [-1, self.vals[0]]
            else:
                temp = [self.vals[pos - 1], self.vals[pos]]
            ret.append(temp)
        return ret


if __name__ == "__main__":
    root = TreeNode(3, TreeNode(2), TreeNode(4))
    # -1,1,3
    s = Solution()
    queries = [-1, 1, 3, 4]
    print(s.closestNodes(root, queries))
