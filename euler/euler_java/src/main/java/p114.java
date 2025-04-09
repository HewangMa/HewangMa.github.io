import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Objects;

public class p114 {
    public static int sum;
    public static int test_size = 29;
    public static List<List<Integer>> brick_lists = new ArrayList<>();
    public static long[] factorial = new long[test_size + 1];

    public static void track_back(List<Integer> bricks, int start) {
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

    public static void main(String[] args) {
        sum = 0;
        factorial[0] = 1;
        for (int i = 1; i <= test_size; i++) factorial[i] = factorial[i - 1] * i;
        track_back(new ArrayList<>(), 3);
        long ans = 0;
        for (int i = 0; i < brick_lists.size(); i++) {
            List<Integer> list = brick_lists.get(i);
//            System.out.print(list);
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
                    ways /= factorial[repeated];
                    repeated = 1;
                }
                j++;
            }
            ways /= factorial[repeated];
            ans += ways;
//            System.out.println("there are ways of " + ways);
        }
        System.out.println(ans);
    }
}
