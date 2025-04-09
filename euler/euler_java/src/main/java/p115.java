import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class p115 {
    public static void main(String[] args) {
        int n = 50;
        solveF s = new solveF();
        while (true) {
            long p = s.solve(50, n);
            if (p > 1000000) {
                System.out.println(n + ", " + p);
                break;
            }
            n++;
        }
    }
}

class solveF {
    private static int start_brick = 3;
    private static int test_size = 29;

    private static int sum;
    private static List<List<Integer>> brick_lists = new ArrayList<>();

    private static void track_back(List<Integer> bricks, int start) {
        if (bricks.size() - 1 + sum > test_size) return;
        brick_lists.add(new ArrayList<>(bricks));
        for (int next_brick = start; next_brick <= test_size; next_brick++) {
            bricks.add(next_brick);
            sum += next_brick;
            track_back(bricks, next_brick);
            bricks.remove(bricks.size() - 1);
            sum -= next_brick;
        }
    }

    public long solve(int mm, int nn) {
        test_size = nn;
        start_brick = mm;
        sum = 0;
        brick_lists.clear();
        track_back(new ArrayList<>(), start_brick);

        long ans = 0;
        for (int i = 0; i < brick_lists.size(); i++) {
            List<Integer> list = brick_lists.get(i);
            int n = list.size();
            int extra = test_size - (n - 1);
            for (int b : list) extra -= b;
            long ways = 1;
            for (int p = 1; p <= n; p++) ways *= (extra + p);
            int repeated = 1;
            int j = 1;
            while (j < n) {
                if (Objects.equals(list.get(j), list.get(j - 1))) repeated++;
                else {
                    for (int p = 2; p <= repeated; p++) ways /= p;
                    repeated = 1;
                }
                j++;
            }
            for (int p = 2; p <= repeated; p++) ways /= p;
            ans += ways;
        }
        return ans;
    }
}