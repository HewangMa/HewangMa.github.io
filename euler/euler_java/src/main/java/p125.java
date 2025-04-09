import java.util.HashSet;

public class p125 {
    private static int test_size = 100000000;
    private static int square_size;

    public static void main(String[] args) {
        HashSet<Long> st = new HashSet<>();
        square_size = (int) Math.sqrt(test_size);
        long[] square_presum = new long[square_size + 1];
        square_presum[0] = 0;
        for (int i = 1; i <= square_size; i++) {
            square_presum[i] = square_presum[i - 1] + (long) i * i;
            if (square_presum[i] < 0) System.out.println("somthing wrong");
        }
        for (int i = 1; i <= square_size; i++) {
            for (int j = i + 1; j <= square_size; j++) {
                long consecutive_sum = square_presum[j] - square_presum[i] + (long) i * i;
                if (consecutive_sum >= test_size) continue;
                StringBuilder sb = new StringBuilder(Long.toString(consecutive_sum));
                StringBuilder reverse = new StringBuilder(sb);
                reverse.reverse();
                if (sb.toString().contentEquals(reverse)) st.add(consecutive_sum);
            }
        }
        long ans_sum = 0;
        for (long l:st) ans_sum+=l;
        System.out.println(ans_sum);
    }
}
