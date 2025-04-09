public class p130 {
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

    private static void run() {
        int wanted_cnt = 25;
        int sum = 0;
        for (int p = 6; ; p++) {
            if (prime(p) || p % 2 == 0 || p % 5 == 0) continue;
            int An = findLeastDivisibleRepunit(p);
            if ((p - 1) % An == 0) {
                wanted_cnt--;
                sum += p;
                if (wanted_cnt <= 0) break;
            }
        }
        System.out.println("the sum: " + sum);
    }

    private static void test() {
        for (int i = 0; i < 100; i++) if (prime(i)) System.out.print(i + ", ");
    }

    public static void main(String[] args) {
        run();
    }
}
