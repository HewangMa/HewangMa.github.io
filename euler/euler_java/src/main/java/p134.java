import java.util.Arrays;

public class p134 {
    private static int test_size = 1000000;

    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    private static int add_prime(int p) {
        int ret = 1;
        while (p > 0) {
            ret *= 10;
            p /= 10;
        }
        return ret;
    }

    public static void main(String[] args) {
        long sum = 0;
        for (int p1 = 5; p1 <= test_size; p1++)
            if (prime(p1)) {
                int p2 = p1 + 1;
                while (!prime(p2)) p2++;
                // 遍历所有的p1，p2
                int add = add_prime(p1);
                long s = add + p1;
                while (s % p2 != 0) s += add;
                sum += s;
//                System.out.println("for " + p1 + " and " + p2 + ", we get s = " + s);
            }
        System.out.println(sum);
    }
}
