import java.math.BigDecimal;
import java.math.BigInteger;

public class p2807 {
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solutionp2807 {

    public int gcd(int a, int b) {
        int c = Math.max(a, b);
        while (a % c != 0 || b % c != 0) c--;
        return c;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode p = head;
        while (p != null && p.next != null) {
            ListNode insert = new ListNode(gcd(p.val, p.next.val), p.next);
            p.next = insert;
            p = insert.next;
        }
        return head;
    }
}