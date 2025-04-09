import java.util.Arrays;

public class p113 {
    public static long inc_cnt = 0;
    public static long dec_cnt = 0;
    public static int up_bound_length = 101;
    public static int print_cnt = 0;

    public static void inc_track_back(StringBuilder n, int start_digit) {
        if (n.length() > 0 && n.length() >= up_bound_length) return;
        if (n.length() > 0 && n.charAt(0) != '0') inc_cnt++;
        for (int i = start_digit; i <= 9; i++) {
            n.append(i);
            inc_track_back(n, i);
            n.deleteCharAt(n.length() - 1);
        }
    }

    public static void dec_track_back(StringBuilder n, int start_digit) {
        if (n.length() > 0 && n.length() >= up_bound_length) return;
        if (n.length() > 0 && n.charAt(0) != '0' && n.charAt(0) != n.charAt(n.length() - 1)) dec_cnt++;
        for (int i = start_digit; i >= 0; i--) {
            n.append(i);
            dec_track_back(n, i);
            n.deleteCharAt(n.length() - 1);
        }
    }

    public static void track_back(String[] args) {
        inc_track_back(new StringBuilder(), 0);
        dec_track_back(new StringBuilder(), 9);
        System.out.println(inc_cnt + dec_cnt);
    }

    public static void main(String[] args) {
        long[][] inc = new long[101][10];
        // inc[i][j] 表示以j开头的长度为i的升序数有多少个
        for (long[] ints : inc) Arrays.fill(ints, 0);
        for (int j = 0; j <= 9; j++) inc[1][j] = 1;
        //inc[i][j] = inc[i - 1][j. .9];
        for (int i = 2; i <= 100; i++)
            for (int j = 9; j >= 0; j--) // 这里的循环是将后缀和数组写完之后的简化
                if (j == 9) inc[i][j] = inc[i - 1][j];
                else inc[i][j] = inc[i][j + 1] + inc[i - 1][j];

        long[][] dec = new long[101][10];
        // dec[i][j] 表示以j开头的长度为i的降序数有多少个
        for (long[] ints : dec) Arrays.fill(ints, 0);
        for (int j = 0; j <= 9; j++) dec[1][j] = 1;
        //dec[i][j] = dec[i - 1][0..j];
        for (int i = 2; i <= 100; i++)
            for (int j = 0; j <= 9; j++) // 这里的循环是将前缀和数组写完之后的简化
                if (j == 0) dec[i][j] = dec[i - 1][j];
                else dec[i][j] = dec[i][j - 1] + dec[i - 1][j];
        long cnt = 0;
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 9; j++) {
                cnt += inc[i][j];
                cnt += dec[i][j];
            } // 这里输出13005 没问题， 需要减掉既是升序数又是降序数的数
        for (int repeat_digit = 1; repeat_digit <= 9; repeat_digit++)
            for (int len = 1; len <= 100; len++)
                cnt -= 1;
        System.out.println(cnt);
    }
}
