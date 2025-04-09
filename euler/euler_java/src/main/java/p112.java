import java.util.Arrays;

public class p112 {
    public static boolean inc_or_dec(int n) {
        char[] origin_chars = String.valueOf(n).toCharArray();
        char[] sorted_chars = String.valueOf(n).toCharArray();
        Arrays.sort(sorted_chars);
        int len = sorted_chars.length;
        boolean inc_tag = true;
        for (int i = 0; i < len; i++)
            if (sorted_chars[i] != origin_chars[i]) {
                inc_tag = false;
                break;
            }
        boolean dec_tag = true;
        for (int i = 0; i < len; i++)
            if (sorted_chars[i] != origin_chars[len - i - 1]) {
                dec_tag = false;
                break;
            }
        return inc_tag || dec_tag;
    }

    public static void main(String[] args) {
//        System.out.println(inc_or_dec(155349));
        int p = 1;
        int not_bouncy_cnt = 0;
        while (true) {
            if (inc_or_dec(p)) not_bouncy_cnt++;
            if (not_bouncy_cnt * 100 == p) {
                System.out.println(p);
                break;
            }
            p++;
        }
    }
}
