public class p135 {
    private static int test_size = 1000000;

    private static String run() {
        int[] solutions = new int[test_size];
        for (int m = 1; m < test_size * 2; m++) {
            for (int k = m / 5 + 1; k * 2 < m; k++) {
                long temp = (long)(m - k) * (k * 5 - m);
                if (temp >= solutions.length)
                    break;
                solutions[(int)temp]++;
            }
        }

        int count = 0;
        for (int x : solutions) {
            if (x == 10)
                count++;
        }
        return Integer.toString(count);
    }

    private static int find_solutions_number(int n) {
        int ret = 0;
        for (int m = 2; m <= n; m++) {
            long p = (long) m * m + n;
            if (p % (4L * m) != 0) continue;
            long k = p / 4 / m;
            if (!(m > k)) continue;
            ret++;
            if (ret > 10) return ret;
        }
        return ret;
    }

    public static void main(String[] args) {
//        int cnt = 0;
//        for (int n = 0; n < test_size; n++)
//            if (find_solutions_number(n) == 10) {
//                System.out.println(n);
//                cnt++;
//            }
//        System.out.println(cnt);
        System.out.println(run())
        ;
    }
}
