import java.util.ArrayList;
import java.util.List;

public class p138 {
    public static void main(String[] args) {
//        Node test_node = new Node(1);
//        for (int i = 0)
    }
}

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
    public void printList(Node head) {
        for (Node p = head; p != null; p = p.next) System.out.println(p.val + ", ");
        System.out.println();
    }

    public Node copyRandomList(Node head) {
        if (head == null) return null;
        List<Node> origin_list = new ArrayList<>();
        List<Node> copy_list = new ArrayList<>();
        int n = 0;
        for (Node p = head; p != null; p = p.next) {
            origin_list.add(p);
            Node t = new Node(p.val);
            copy_list.add(t);
            n++;
        }
        Node ret = new Node(0);
        for (int i = 0; i < n; i++) {
            Node p = origin_list.get(i);
            int next_i = origin_list.indexOf(p.next);
            int randon_i = origin_list.indexOf(p.random);
            Node t = copy_list.get(i);
            if (next_i == -1) t.next = null;
            else t.next = copy_list.get(next_i);
            if (randon_i == -1) t.random = null;
            else t.random = copy_list.get(randon_i);
        }
        return copy_list.get(0);
    }
}