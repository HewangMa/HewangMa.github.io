# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self) -> str:
        return str(self.val)


class Solution0:
    # 有的情况没有考虑到
    def isCousins(self, root, x, y):
        if not root:
            return False
        lc = root.left
        rc = root.right
        if not lc:
            return self.isCousins(rc, x, y)
        if not rc:
            return self.isCousins(lc, x, y)

        left_gs = []
        if lc.left:
            left_gs.append(lc.left.val)
        if lc.right:
            left_gs.append(lc.right.val)
        right_gs = []
        if rc.left:
            right_gs.append(rc.left.val)
        if rc.right:
            right_gs.append(rc.right.val)

        if (x in left_gs and y in right_gs) or (y in left_gs and x in right_gs):
            return True

        return self.isCousins(lc, x, y) or self.isCousins(rc, x, y)


class Solution:
    def __init__(self) -> None:
        self.parent = {}
        self.paths = []

    def post_order(self, root, parent=None):
        if root:
            self.post_order(root.left, root)
            self.post_order(root.right, root)
            self.parent[root] = parent

    def pre_order(self, root, x):
        if root:
            if root.val == x:
                p = self.parent[root]
                ret = [root.val]
                while p:
                    ret.append(p.val)
                    p = self.parent[p]
                self.paths.append(ret[::-1])
            self.pre_order(root.left, x)
            self.pre_order(root.right, x)

    def isCousins(self, root, x, y):
        self.post_order(root)
        self.pre_order(root, x)
        self.pre_order(root, y)
        print(self.paths)
        if x in self.paths[1]:
            return False
        if y in self.paths[0]:
            return False
        i = 0
        while self.paths[0][i] == self.paths[1][i]:
            i += 1
        xp, yp = i, i
        while self.paths[0][xp] != x:
            xp += 1
        while self.paths[1][yp] != y:
            yp += 1
        return xp == yp and xp != i


if __name__ == "__main__":
    root = TreeNode(2, TreeNode(3), TreeNode(4, None, TreeNode(5)))
    root = TreeNode(1, root)
    s = Solution()
    print(s.isCousins(root, 2, 4))
