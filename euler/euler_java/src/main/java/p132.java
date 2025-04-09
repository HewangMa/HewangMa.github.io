import com.sun.xml.internal.ws.addressing.WsaActionUtil;
import sun.awt.image.PixelConverter;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class p132 {
    private static int target = (int) 1E9;

    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    private static int findLeastDivisibleRepunit(int n) {
        if (n > Integer.MAX_VALUE / 10)
            throw new IllegalArgumentException("Arithmetic overflow");
        int sum = 1;  // R(k) mod n
        int pow = 1;  // mod n
        int k = 1;
        while (sum % n != 0) {
            // 这种找 111..111 的方式免去了大整数相除，所有对于大整数相除的计算都应该采用这种方式
            k++;
            pow = pow * 10 % n;
            sum = (sum + pow) % n;
        }
        return k;
    }

    private static boolean DivisibleKRepunit(int n, int k) {
        if (n > Integer.MAX_VALUE / 10)
            throw new IllegalArgumentException("Arithmetic overflow");
        int sum = 1;  // R(k) mod n
        int pow = 1;  // mod n
        while (k > 1) {
            pow = pow * 10 % n;
            sum = (sum + pow) % n;
            k--;
        }
        return sum % n == 0;
    }


    private static void test() {
//        StringBuilder r = new StringBuilder();
//        for (int i = 0; i < target; i++) r.append(1);
//        BigInteger R = new BigInteger(r.toString());
//        if (R.remainder(new BigInteger("7")).equals(BigInteger.ZERO)) System.out.println("yes");
//        if (DivisibleKRepunit(17, (int) 1E9)) System.out.println("yes");
//        else System.out.println("no");
//        System.out.println((int) 1E9);
//        int target = (int) 1E9;
//        int cnt = 0;
//        while (target % 2 == 0) {
//            cnt++;
//            target /= 2;
//        }
//        System.out.println(cnt);
//        for (int i = 0; ; i++) {
//            if (prime(i) && DivisibleKRepunit(i, 6) && !DivisibleKRepunit(i, 3)) {
//                System.out.println(i);
//                break;
//            }
//        }
    }

    private static void run3() {
        int cnt = 0;
        int sum = 0;
        int print_cnt = 0;
        for (int i = 3; ; i++)
            if (prime(i)) {
                if (i == 5) continue;
                int An = findLeastDivisibleRepunit(i);
                if (target % An == 0) {
                    sum += i;
                    System.out.print(i + ", ");
                    print_cnt++;
                    if (print_cnt % 10 == 0) System.out.println();
                    cnt++;
                    if (cnt >= 40) break;
                }
            }
        System.out.println(sum);
    }

    private static void run2() {
        List<Integer> ps = new ArrayList<>();
        while (target % 2 == 0) {
            ps.add(target);
            target /= 2;
        }
        ps.add(target);
        Collections.reverse(ps);
        System.out.println(ps);
        int cnt = 0;
        for (int i = 17; ; i++) {
            if (prime(i)) {
                System.out.println("trying " + i);
                for (int p : ps) {
                    System.out.println("trying R(" + p + "); ");
                    if (DivisibleKRepunit(i, p)) cnt++;
                }
            }
        }
    }

    private static void run1() {
        StringBuilder r = new StringBuilder();
        for (int i = 0; i < target; i++) r.append(1);
        BigInteger R = new BigInteger(r.toString());
        for (int j = 2; j < 10; j++)
            if (R.remainder(new BigInteger(Integer.toString(j))).equals(BigInteger.ZERO))
                System.out.println("below 10: " + j);
        int i = 11;
        BigInteger ad = new BigInteger("10");
        BigInteger I = new BigInteger(Integer.toString(i));
        BigInteger last = new BigInteger("2");
        int fac_cnt = 0;
        while (R.compareTo(I) >= 0) {
            if (R.remainder(I).equals(BigInteger.ZERO)) {
                if (!I.equals(last)) System.out.println(I);
                last = I;
                fac_cnt++;
                if (fac_cnt >= 40) break;
                R = R.divide(I);
            } else I = I.add(ad);
        }
    }

    public static void main(String[] args) {
//        test();
        run3();
    }
}
