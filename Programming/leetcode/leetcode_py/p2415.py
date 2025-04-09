# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue


class Solution:
    def reverseOddLevels(self, root):
        que = Queue()
        que.put(root)
        level = 0
        while que.qsize():
            size = que.qsize()
            nodes = []
            vals = []
            print(que.qsize())
            while size > 0:
                node = que.get()
                nodes.append(node)
                vals.append(node.val)
                if node.left:
                    que.put(node.left)
                    que.put(node.right)
                size -= 1
            if level % 2 == 1:
                vals = vals[::-1]
                for i in range(len(nodes)):
                    nodes[i].val = vals[i]
            level += 1
        return root
