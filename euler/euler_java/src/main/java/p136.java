public class p136 {
    private static int test_size = 50000000;

    private static String run() {
        int[] solutions = new int[test_size];
        for (int m = 1; m < test_size; m++) {
            for (int k = m / 4 + 1; k < m; k++) {
                long temp = (long) m * (4L * k - m);
                if (temp >= solutions.length)
                    break;
                solutions[(int) temp]++;
            }
        }

        int count = 0;
        for (int x : solutions) {
            if (x == 1)
                count++;
        }
        return Integer.toString(count);
    }

    private static int find_solutions_number(int n) {
        int cnt = 0;
        if (n % 4 == 3) {
            cnt++;
            // 存在m==n 必然成立
            for (int m = 2; m < n; m++) {
                long p = (long) m * m * n;
                if (p % (4L * m) != 0) continue;
                long k = p / 4 / m;
                if (m <= k) continue;
                cnt++;
                if (cnt > 1) return cnt;
            }
        }
        return 1;
//        }
//        for (int m = 2; m <= n; m++) {
//            long p = (long) m * m + n;
//            if (p % (4L * m) != 0) continue;
//            long k = p / 4 / m;
//            if (m <= k) continue;
//            ret++;
//            if (n % 4 == 3)
//        }
//        return ret;
    }

    public static void main(String[] args) {
//        int print_cnt = 0;
//        int cnt = 0;
//        for (int n = 1; n < test_size; n++) {
//            if (find_solutions_number(n) == 1) {
//                cnt++;
//                if (n % 101 == 0) {
//                    print_cnt++;
//                    System.out.print(n + ", ");
//                    if (print_cnt % 6 == 5) System.out.println();
//                }
//            }
//        }
//        System.out.println(cnt);
        System.out.println(run());
    }
}
