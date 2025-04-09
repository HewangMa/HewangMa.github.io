import java.util.*;


public class p128_1 {

    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    public static void grid() {
        int grid_size = 100;
//        HashMap<List<Integer>, Integer> seq1 = new HashMap<>();
//        HashMap<List<Integer>, Integer> seq2 = new HashMap<>();
//        HashMap<List<Integer>, Integer> seq3 = new HashMap<>();
        int[][] grid = new int[grid_size][grid_size];
        for (int[] ints : grid) Arrays.fill(ints, 0);
        int pos_add = grid_size / 2;
        // 斜坐标系中 grid[x][y] 表示(x,y)
        int x = 0, y = 0;
        grid[x + pos_add][y + pos_add] = 1;
        y = 1;
        int p = 1;
        int dir = 0;
        int x_left_bound = -1;
        int x_right_bound = 1;
        while (true) {
            p++;
            assert p > 0;
            if (x_right_bound + 3 > grid_size / 2) break;
            grid[x + pos_add][y + pos_add] = p;
            if (dir == 0) {
                x--;
                if (x <= x_left_bound) {
                    dir = 1;
                    x_left_bound--;
                }
            } else if (dir == 1) {
                y--;
                if (y <= 0) dir = 2;
            } else if (dir == 2) {
                x++;
                y--;
                if (x >= 0) dir = 3;
            } else if (dir == 3) {
                x++;
                if (x >= x_right_bound) {
                    dir = 4;
                    x_right_bound++;
                }
            } else if (dir == 4) {
                y++;
                if (y >= 0) dir = 5;
            } else if (dir == 5) {
                x--;
                y++;
                if (x <= 0) {
                    y++;
                    dir = 0;
                }
            }
        }
        List<Integer> seq = new ArrayList<>();
        for (x = x_left_bound; x <= x_right_bound; x++) {
            for (y = x_left_bound; y <= x_right_bound; y++) {
                int t = grid[x + pos_add][y + pos_add];
//                System.out.print(t + ", ");
                int t0 = grid[x + pos_add][y + 1 + pos_add];
                int t1 = grid[x - 1 + pos_add][y + 1 + pos_add];
                int t2 = grid[x - 1 + pos_add][y + pos_add];
                int t3 = grid[x + pos_add][y - 1 + pos_add];
                int t4 = grid[x + 1 + pos_add][y - 1 + pos_add];
                int t5 = grid[x + 1 + pos_add][y + pos_add];
                int prime_diff = 0;
                if (prime(Math.abs(t0 - t))) prime_diff++;
                if (prime(Math.abs(t1 - t))) prime_diff++;
                if (prime(Math.abs(t2 - t))) prime_diff++;
                if (prime(Math.abs(t3 - t))) prime_diff++;
                if (prime(Math.abs(t4 - t))) prime_diff++;
                if (prime(Math.abs(t5 - t))) prime_diff++;
                if (prime_diff >= 3) seq.add(t);
            }
        }
        Collections.sort(seq);
        System.out.println("seq.size: " + seq.size());
        for (int i = 0; i < seq.size(); i++) {
            System.out.print(seq.get(i) + ", ");
            if (i % 10 == 9) System.out.println();
        }
    }

    public static void main(String[] args) {
        grid();
        /*
        1, 2, 8, 19, 20, 37, 61, 128, 217, 271, 401, 409, 419,
         */
    }
}
