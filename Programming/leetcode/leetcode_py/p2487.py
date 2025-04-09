# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNodes(self, head):
        st = []
        node = head
        while node:
            while st and st[-1] < node.val:
                st.pop()
            st.append(node.val)
            node = node.next
        n = len(st)
        node = ListNode(st[-1])
        for i in range(-2, -n - 1, -1):
            node = ListNode(st[i], node)
        return node
