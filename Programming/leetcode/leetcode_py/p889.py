# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructFromPrePost(self, preorder, postorder):
        if len(preorder) == 0:
            return None
        if len(preorder) == 1:
            return TreeNode(preorder[0])
        if len(preorder) >= 2:
            root_val = preorder[0]
            left_val = preorder[1]
            left_size = postorder.index(left_val) + 1
            left = self.constructFromPrePost(
                preorder[1 : 1 + left_size], postorder[:left_size]
            )
            right = self.constructFromPrePost(
                preorder[1 + left_size :], postorder[left_size:-1]
            )
            return TreeNode(root_val, left, right)
