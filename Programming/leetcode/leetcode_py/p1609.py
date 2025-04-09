# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue


class Solution:
    def isEvenOddTree(self, root):
        que = Queue()
        node = root
        que.put(node)
        level = 0
        while que:
            size = que.qsize()
            print(que)
            if level % 2 == 0:
                min = 0
                while size > 0:
                    size -= 1
                    node = que.get()
                    print(que.qsize())
                    if not (node.val % 2 == 1 and node.val > min):
                        return False
                    min = node.val
                    if node.left:
                        que.put(node.left)
                    if node.right:
                        que.put(node.right)
            else:
                max = 0x7FFFFFFF
                while size > 0:
                    size -= 1
                    node = que.get()

                    if not (node.val % 2 == 0 and node.val < max):
                        return False
                    max = node.val
                    if node.left:
                        que.put(node.left)
                    if node.right:
                        que.put(node.right)
            level += 1
        return True
