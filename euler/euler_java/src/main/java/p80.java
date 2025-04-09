import sun.applet.AppletResourceLoader;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;

public class p80 {
    public static void main(String[] args) {
        p80.solve1();
    }

    public static int digitsSum(BigDecimal x) {
        String n_str = x.toString();
        int ret = 0;
        for (int i = 0; i < 101; i++) {
            if (n_str.charAt(i) == '.') continue;
            ret += Integer.parseInt(String.valueOf(n_str.charAt(i)));
        }
        return ret;
    }

    public static BigDecimal sqrt_Newton(int a) {
        MathContext precision = new MathContext(102);
        BigDecimal A = new BigDecimal(a, precision);
        BigDecimal n = new BigDecimal("2", precision);
        BigDecimal x = new BigDecimal("1", precision);
        BigDecimal ori;
        do {
            ori = x;
            x = x.add(A.divide(x, precision)).divide(n, precision);
        } while (!x.equals(ori));
        return x;
    }

    public static void solve1() {
        int total_sum = 0;
        for (int i = 2; i < 100; i++) {
            BigDecimal x = sqrt_Newton(i);
            int temp = digitsSum(x);
            if (temp > 120) total_sum += temp;
            System.out.println(i + " sum to " + temp);
        }
        System.out.println(total_sum);
    }
}
