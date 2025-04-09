import java.util.ArrayList;
import java.util.List;

public class p25 {
    public static void main(String[] args) {
        Solutionp25 s = new Solutionp25();
        ListNode testList = new ListNode(1);
        for (int i = 2; i <= 14; i++) testList = new ListNode(i, testList);
        System.out.println("the origin ListNode:");
        s.printListNode(testList);
        ListNode p = s.reverseKGroup(testList, 3);
        System.out.println("after k reverse:");
        s.printListNode(p);
    }
}
class Solutionp25 {
    public ListNode[] reverse(ListNode head) {
        ListNode new_head = new ListNode();
        ListNode p = head;
        while (p != null) {
            ListNode r = p.next;
            p.next = new_head.next;
            new_head.next = p;
            p = r;
        }
        ListNode[] ret = new ListNode[2];
        ret[0] = new_head.next;
        ret[1] = head;
        return ret;
    }

    public void printListNode(ListNode head) {
        for (ListNode p = head; p != null; p = p.next) System.out.print(p.val + ", ");
        System.out.println();
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        int cnt = 0;
        List<ListNode> groups = new ArrayList<>();
        ListNode p = head;
        while (p != null) {
            ListNode r = p.next;
            cnt += 1;
            if (cnt == k) {
                p.next = null;
                cnt = 0;
                groups.add(head);
                head = r;
            }
            p = r;
        }
//        if (cnt != 0) groups.add(head);
        System.out.println("the groups:");
        for (ListNode kp : groups) printListNode(kp);
        ListNode[] reverse_ = reverse(groups.get(0));
        ListNode ret_head = reverse_[0];
        ListNode reversed_tail = reverse_[1];
        for (int i = 1; i < groups.size(); i++) {
            reverse_ = reverse(groups.get(i));
            reversed_tail.next = reverse_[0];
            reversed_tail = reverse_[1];
        }
        reversed_tail.next = head;
        return ret_head;
    }
}
