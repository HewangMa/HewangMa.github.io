public class p93 {
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

        public ListNode rotateRight(ListNode head, int k) {
            ListNode p = head;
            int len = 0;
            while (p != null) {
                p = p.next;
                len++;
            }
            list_len = len;
            head = reverseFrom(head, list_len - k);
            print_List(head);
            head = reverseFrom(head, 1);
            print_List(head);
            head = reverseFrom(head, k);
            print_List(head);
            return head;
        }
    }
}
