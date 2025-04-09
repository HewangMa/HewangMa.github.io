from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self) -> None:
        self.level_sum = {}
        self.parent = {}

    def get_level(self, root):
        que = deque()
        que.append(root)
        level = 0
        while que:
            size = len(que)
            sum = 0
            while size:
                size -= 1
                node = que.popleft()
                sum += node.val
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
            self.level_sum[level] = sum
            level += 1

    def get_parents(self, root, parent=None):
        if root:
            self.get_parents(root.left, root)
            self.get_parents(root.right, root)
            self.parent[root] = parent

    def post_order(self, root, depth):
        if root:
            left = self.post_order(root.left, depth + 1)
            right = self.post_order(root.right, depth + 1)

            p = self.parent[root]
            if not p:
                return TreeNode(0, left, right)
            
            sum = self.level_sum[depth]
            if p.left:
                sum -= p.left.val
            if p.right:
                sum -= p.right.val

            return TreeNode(sum, left, right)

        return None

    def replaceValueInTree(self, root):
        # 思路是记录 {深度：节点值和} 和 {节点：父亲}
        self.get_level(root)
        self.get_parents(root)
        return self.post_order(root, 0)
