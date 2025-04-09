import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class p127 {
    private static final int test_size = 120000;

    private static int find_gcd(int a, int b) {
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        while (a >= 1) {
            int t = b % a;
            b = a;
            a = t;
        }
        return b;
    }

    private static HashSet<Integer> prime_facs(int n, int[] rads) {
        int i = 2;
        HashSet<Integer> facs = new HashSet<>();
        while (i <= n)
            if (n % i == 0) {
                n /= i;
                if (!facs.contains(i)) {
                    facs.add(i);
                    rads[0] *= i;
                }
            } else i++;
        return facs;
    }

    private static int rad(int n) {
        int proc = 1;
        int i = 2;
        HashSet<Integer> facs = new HashSet<>();
        while (i <= n)
            if (n % i == 0) {
                n /= i;
                facs.add(i);
            } else i++;
        for (int fac : facs) proc *= fac;
        return proc;
    }

    public static void brute_from_c() {
        int[] rads = new int[test_size];
        Arrays.fill(rads, 1, rads.length, 1);
        for (int i = 2; i < rads.length; i++)
            if (rads[i] == 1)
                for (int j = i; j < rads.length; j += i)
                    rads[j] *= i;

        long sum = 0;
        for (int c = 1; c < test_size; c++) {
            if (rads[c] >= c) continue;
            for (int a = 1; a <= c / 2; a++) {
                int b = c - a;
                assert b > a;
                if ((long) rads[c] * rads[a] * rads[b] < c && find_gcd(a, b) == 1) {
                    sum += c;
                    assert sum > 0;
                }
            }
        }
        System.out.println(sum);
//        System.out.println(find_gcd(23, 17));
    }

    public static void brute_from_a() {
        long sum = 0;
        Scanner sc = new Scanner(System.in);
        for (int a = 1; a + a + 1 < test_size; a++) {
            int[] a_rad = new int[]{1};
            HashSet<Integer> a_facs = prime_facs(a, a_rad);
            for (int b = a + 1; a + b < test_size; b++) {
                int c = a + b;
                if (a_rad[0] >= c) continue;
                // a b不互质
                boolean mutual_prime = true;
                for (int fac : a_facs)
                    if (b % fac == 0) {
                        mutual_prime = false;
                        break;
                    }
                if (!mutual_prime) continue;

                int[] b_rad = new int[]{1};
                HashSet<Integer> b_fac = prime_facs(b, b_rad);
                if (b_rad[0] >= c) continue;

                //b c不互质
//                for (int fac : b_fac)
//                    if (c % fac == 0) {
//                        mutual_prime = false;
//                        break;
//                    }
//                if (!mutual_prime) continue;


                int[] c_rad = new int[]{1};
                HashSet<Integer> c_fac = prime_facs(c, c_rad);
                int abc_rad = a_rad[0] * b_rad[0] * c_rad[0];
                if (abc_rad < c) {
                    if (c % 1000 == 0)
                        System.out.println("a: " + a + ", b: " + b + ", c: " + c);
                    sum += c;
                    if (sum < 0) System.out.println("something wrong");
                }
            }
        }
        System.out.println(sum);
    }

    public static void test_functions() {
        int a = 160;
        int[] rad = new int[]{1};
        HashSet<Integer> facs = prime_facs(a, rad);
        System.out.println(facs);
        System.out.println(rad[0]);
        /*
        a: 2, b: 243, c: 245
a: 3, b: 125, c: 128
a: 4, b: 121, c: 125
a: 5, b: 27, c: 32
a: 5, b: 507, c: 512
a: 7, b: 243, c: 250
a: 13, b: 243, c: 256
a: 25, b: 704, c: 729
a: 27, b: 512, c: 539
a: 32, b: 49, c: 81
a: 32, b: 343, c: 375
a: 49, b: 576, c: 625
a: 81, b: 175, c: 256
a: 81, b: 544, c: 625
a: 100, b: 243, c: 343
a: 104, b: 625, c: 729
a: 169, b: 343, c: 512
a: 200, b: 529, c: 729
a: 343, b: 625, c: 968
8059
         */
    }

    public static void ref() {
        int[] rads = new int[test_size];
        Arrays.fill(rads, 1, rads.length, 1);
        for (int i = 2; i < rads.length; i++)
            if (rads[i] == 1)
                for (int j = i; j < rads.length; j += i)
                    rads[j] *= i;

        long sum = 0;
        for (int c = 2; c < test_size; c++) {
            if (rads[c] == c)
                continue;
            for (int a = 1, end = (c - 1) / 2; a <= end; a++) {
                int b = c - a;
                assert a < b;
                if ((long) rads[a] * rads[b] * rads[c] < c && find_gcd(a, b) == 1)
                    sum += c;
            }
        }
        System.out.println(Long.toString(sum));
    }

    public static void main(String[] args) {
//        brute_from_a();
        brute_from_c();
//        test_functions();
//        ref();
    }
}
