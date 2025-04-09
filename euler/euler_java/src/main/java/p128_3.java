import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;


public class p128_3 {

    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    private static boolean is_tile(int t, List<Integer> neighbors) {
        int cnt = 0;
        for (int nei : neighbors)
            if (prime(Math.abs(nei - t))) cnt++;
        return cnt == 3;
    }

    private static List<Integer> cal_tiles(List<Integer> seq1, List<Integer> seq2, List<Integer> seq3) {
        int l2 = seq2.size() / 6;
        List<Integer> ret = new ArrayList<>();
        for (int i = 0; i < seq2.size(); i++) {
            int t = seq2.get(i);
            List<Integer> neighbors = new ArrayList<>();
            if (i / l2 == 0) { // first vertex and edge
                if (i % l2 == 0) {
                    neighbors.add(seq1.get(0));

                    neighbors.add(seq2.get(1));
                    neighbors.add(seq2.get(seq2.size() - 1));

                    neighbors.add(seq3.get(0));
                    neighbors.add(seq3.get(1));
                    neighbors.add(seq3.get(seq3.size() - 1));
                } else {
                    neighbors.add(seq1.get(i));
                    neighbors.add(seq1.get(i + 1));

                    neighbors.add(seq2.get(i + 1));
                    neighbors.add(seq2.get(i - 1));

                    neighbors.add(seq3.get(i - 1));
                    neighbors.add(seq3.get(i));
                }
            } else if (i / l2 == 1) { // second vertex and edge
                if (i % l2 == 0) {
                    // end
                    neighbors.add(seq1.get(i - 1));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i));
                    neighbors.add(seq3.get(i + 1));
                    neighbors.add(seq3.get(i + 2));
                } else {
                    neighbors.add(seq1.get(i - 2));
                    neighbors.add(seq1.get(i - 1));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 1));
                    neighbors.add(seq3.get(i + 2));
                }
            } else if (i / l2 == 2) { // third vertex and edge
                if (i % l2 == 0) {
                    neighbors.add(seq1.get(i - 2));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 1));
                    neighbors.add(seq3.get(i + 2));
                    neighbors.add(seq3.get(i + 3));
                } else {
                    neighbors.add(seq1.get(i - 3));
                    neighbors.add(seq1.get(i - 2));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 2));
                    neighbors.add(seq3.get(i + 3));
                }
            } else if (i / l2 == 3) { // fourth vertex and edge
                if (i % l2 == 0) {
                    neighbors.add(seq1.get(i - 3));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 2));
                    neighbors.add(seq3.get(i + 3));
                    neighbors.add(seq3.get(i + 4));
                } else {
                    neighbors.add(seq1.get(i - 4));
                    neighbors.add(seq1.get(i - 3));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 3));
                    neighbors.add(seq3.get(i + 4));
                }
            } else if (i / l2 == 4) { // fifth vertex and edge
                if (i % l2 == 0) {
                    neighbors.add(seq1.get(i - 4));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 3));
                    neighbors.add(seq3.get(i + 4));
                    neighbors.add(seq3.get(i + 5));
                } else {
                    neighbors.add(seq1.get(i - 5));
                    neighbors.add(seq1.get(i - 4));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 4));
                    neighbors.add(seq3.get(i + 5));
                }
            } else if (i / l2 == 5) { // sixth vertex and edge
                if (i % l2 == 0) {
                    neighbors.add(seq1.get(i - 5));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(i + 1));

                    neighbors.add(seq3.get(i + 4));
                    neighbors.add(seq3.get(i + 5));
                    neighbors.add(seq3.get(i + 6));
                } else {
                    neighbors.add(seq1.get(i - 6));
                    neighbors.add(seq1.get(0));

                    neighbors.add(seq2.get(i - 1));
                    neighbors.add(seq2.get(0));


                    neighbors.add(seq3.get(i + 5));
                    neighbors.add(seq3.get(i + 6));
                }
            }

            if (t == 123) {
                System.out.println(seq1);
                System.out.println(seq2);
                System.out.println(seq3);
                System.out.println("neighbors of 123: " + neighbors);
            }

            if (is_tile(t, neighbors)) ret.add(t);
        }
        return ret;
    }

    private static void put_in(List<Integer> seq, int len, int start) {
        assert start > 0;
        int cnt = (len - 1) * 6;
        if (len == 1) cnt = 1;
        while (cnt > 0) {
            cnt--;
            seq.add(start++);
        }
    }

    private static void three_list() {
        int turns = 20;
        List<Integer> seq1 = new ArrayList<>();
        List<Integer> seq2 = new ArrayList<>();
        List<Integer> seq3 = new ArrayList<>();
        List<Integer> all_tiles = new ArrayList<>();
        all_tiles.add(1);
        all_tiles.add(2);
        put_in(seq1, 2, 2);
        put_in(seq2, 3, 8);
        put_in(seq3, 4, 20);
        int start = 20;
        int len = 4;
        while (turns > 0) {
            turns--;
            List<Integer> tiles = cal_tiles(seq1, seq2, seq3);
            System.out.println("added: " + tiles);
            all_tiles.addAll(tiles);
            start = start + (len - 1) * 6;
            len++;
            seq1.clear();
            seq1.addAll(seq2);
            seq2.clear();
            seq2.addAll(seq3);
            seq3.clear();

            put_in(seq3, len, start);
//            System.out.println("seq1: " + seq1);
//            System.out.println("seq2: " + seq2);
//            System.out.println("seq3: " + seq3);
//            System.out.println();
        }
        Collections.sort(all_tiles);
        System.out.println(all_tiles);
//        List<Integer> all_tiles = new ArrayList<>();
//        while (turns > 0) {
//            turns--;
//            start += (len - 1) * 6;
//            seq1 = seq2;
//            seq2 = seq3;
//            put_in(seq3, ++len, start);
//            List<Integer> tiles = cal(seq1, seq2, seq3);
//            all_tiles.addAll(tiles);
//        }
//        Collections.sort(all_tiles);
//        System.out.println(all_tiles);

    }

    public static void main(String[] args) {
        three_list();
    }
}
