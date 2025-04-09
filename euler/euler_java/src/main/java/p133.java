public class p133 {
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

    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    private static boolean only25(int a) {
        while (a % 2 == 0) a /= 2;
        while (a % 5 == 0) a /= 5;
        return a == 1;
    }

    private static int test_size = 100000;

    private static void run() {
        long sum = 7;
        for (int i = 0; i < test_size; i++)
            if (prime(i)) {
                if (i == 2 || i == 5) continue;
                int An = findLeastDivisibleRepunit(i);
                if (only25(An)) {
                    System.out.println("p = " + i + " its An = " + An);
                    continue;
                }
                sum += i;
//                System.out.println("p = " + i + " its An = " + An);
            }
        System.out.println(sum);
    }

    public static void main(String[] args) {
        run();
    }

}
