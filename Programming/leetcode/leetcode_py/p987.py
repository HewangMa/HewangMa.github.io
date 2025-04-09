class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self) -> None:
        self.matrix = {}
        self.most_left = 0
        self.most_right = 0
        self.most_down = 0

    def put_matrix(self, root, row=0, col=0):
        if root:
            pos = (row, col)
            print(f"node {root.val} at ({pos})")
            self.most_left = min(self.most_left, col)
            self.most_right = max(self.most_right, col)
            self.most_down = max(self.most_down, row)
            if pos in self.matrix:
                self.matrix[pos].append(root.val)
            else:
                self.matrix[pos] = [root.val]
            self.put_matrix(root.left, row + 1, col - 1)
            self.put_matrix(root.right, row + 1, col + 1)

    def verticalTraversal(self, root):
        self.put_matrix(root)
        ret = []
        for col in range(self.most_left, self.most_right + 1):
            temp = []
            for row in range(self.most_down + 1):
                pos = (row, col)
                if pos in self.matrix:
                    node_here = sorted(self.matrix[pos])
                    for val in node_here:
                        temp.append(val)
            ret.append(sorted(temp))
        return ret
