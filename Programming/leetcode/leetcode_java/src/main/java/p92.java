import java.util.List;

public class p92 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode() {}
     * ListNode(int val) { this.val = val; }
     * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    static class Solution {
        public static int list_len;

        public static ListNode reverse(ListNode head) {
            ListNode p = head;
            if (p == null) return null;
            ListNode pre = null, r = p.next;
            while (p != null) {
                r = p.next;
                p.next = pre;
                pre = p;
                p = r;
            }
            return pre;
        }

        public static ListNode reverseFrom(ListNode head, int from) {
            ListNode piv = new ListNode(0, head);
            ListNode pre = piv;
            ListNode p = head;
            while (from > 1) {
                from--;
                p = p.next;
                pre = pre.next;
            }
            pre.next = reverse(p);
            return piv.next;
        }

        public static void print_List(ListNode head) {
            ListNode p = head;
            while (p != null) {
                System.out.print(p.val + ", ");
                p = p.next;
            }
            System.out.println();
        }

        public static ListNode reverseBetween(ListNode head, int left, int right) {
            ListNode p = head;
            int len = 0;
            while (p != null) {
                p = p.next;
                len++;
            }
            list_len = len;
            head = reverseFrom(head, left);
            head = reverseFrom(head, list_len - (right - left));
            head = reverseFrom(head, left);
            return head;
        }
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(12, null);
        for (int i = 11; i > 0; i--)
            head = new ListNode(i, head);
        System.out.print("origin list: ");
        Solution.print_List(head);
        System.out.print("converted list: ");
        Solution.print_List(Solution.reverseBetween(head,11,12));
    }
}
