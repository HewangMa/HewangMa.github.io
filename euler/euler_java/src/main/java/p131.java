import com.sun.corba.se.impl.resolver.SplitLocalResolverImpl;

import java.util.ArrayList;
import java.util.List;

public class p131 {

    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    public static void main(String[] args) {
        int cnt = 0;
        int test_size = 1000000;
        for (int a = 1; ; a++) {
            int p = 3 * a * a + 3 * a + 1;
            if (p >= test_size) break;
            if (prime(p)) cnt++;
        }
        System.out.println(cnt);
    }
}

class p131_0 {
    private static int test_size = 2000;
    private static int cubes_size = test_size * 10;
    private static List<Long> cubes;

    private static boolean cube(long n) {
        return Math.cbrt(n) % 1 == 0;
    }

    private static boolean special(int p) {
        for (int n = 1; n < cubes_size; n++) {
            Long a3 = (long) p * n * n + cubes.get(n);
            if (cubes.contains(a3)) {
                System.out.print("n = " + n + ", p = " + p + ", a = " + cubes.indexOf(a3) + ";  ");
                return true;
            }
        }
        return false;
    }


    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    private static void run() {
        cubes = new ArrayList<>();
        for (long i = 0; i < cubes_size; i++) {
            if (i > Math.cbrt(Long.MAX_VALUE) - 1) throw new IllegalArgumentException("Arithmetic overflow");
            cubes.add(i * i * i);
        }
        int cnt = 0;
        for (int i = 0; i < test_size; i++)
            if (prime(i) && special(i)) {
                cnt++;
                System.out.println("got special " + i);
            }
        System.out.println();
        System.out.println("there are " + cnt + " specials below " + test_size);
    }

    private static void test() {
        for (int i = 0; i < 100; i++) if (cube(i)) System.out.println(i);
    }

    public static void solve(String[] args) {
        run();
//        test();
    }

}
