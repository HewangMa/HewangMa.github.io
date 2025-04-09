import java.util.*;

public class p146 {
    public static void main(String[] args) {
        LRUCache lru = new LRUCache(4);
        lru.put(2, 897);
        lru.put(4, 24);
        lru.put(4, 357);
        lru.put(1, 555);
        lru.put(2, 45);
        lru.put(5, 897);
        lru.put(3, 837);
        lru.printLRU();
    }
}

class LRUCache {
    static class DlinkedNode {
        DlinkedNode() {
        }

        DlinkedNode(int key, int val) {
            this.key = key;
            this.val = val;
        }

        int key;
        int val;
        DlinkedNode pre;
        DlinkedNode next;
    }

    Map<Integer, DlinkedNode> node_map = new HashMap<>();
    DlinkedNode head, tail;
    int size, capacity;

    public LRUCache(int capacity) {
        size = 0;
        head = new DlinkedNode(0, 0);
        tail = new DlinkedNode(0, 0);
        head.next = tail;
        tail.pre = head;
        this.capacity = capacity;
    }

    public int get(int key) {
        DlinkedNode node = node_map.get(key);
        if (node == null) return -1;
        move_to_head(node);
        return head.next.val;
    }

    public void put(int key, int value) {
        if (node_map.containsKey(key)) {
            DlinkedNode node = node_map.get(key);
            node.val = value;
            move_to_head(node);
//            System.out.println("the contained val: "+value);
//            printLRU();
        } else {
            DlinkedNode node = new DlinkedNode(key, value);
            node.next = head.next;
            node.pre = head;
            head.next.pre = node;
            head.next = node;
//            tail.pre.next = node;
            node_map.put(key, node);
            size++;
        }
        if (size > capacity) {
            DlinkedNode to_del = tail.pre;
            to_del.pre.next = tail;
            tail.pre = to_del.pre;
            node_map.remove(to_del.key);
            size--;
        }
    }

    public void move_to_head(DlinkedNode node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;

        DlinkedNode t = head.next;
        head.next = node;
        node.pre = head;
        node.next = t;
        t.pre = node;
//        tail.pre.next = t;
    }

    public void printLRU() {
        DlinkedNode p = head.next;
        int cnt = 0;
        while (cnt < size) {
            System.out.println(p.key + ":" + p.val + ", ");
            p = p.next;
            cnt++;
        }
        System.out.println();
    }
//    public void remove_tail() {
//        DlinkedNode t = tail.pre;
//        t.next = head.next;
//        head.next.pre = t;
//        tail = t;
//    }
}
