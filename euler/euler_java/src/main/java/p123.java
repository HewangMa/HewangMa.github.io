public class p123 {
    private static long remainder(int p, int n) {
        if (n % 2 == 0) return 2;
        else return (long) 2 * n * p;
    }

    private static boolean prime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    public static void main(String[] args) {
        int n = 1;
        int p = 2;
        while (true) {
            if (prime(p)) {
                long r = remainder(p, n);
                if (r > 10000000000l){
                    System.out.println(p + ", " + n);
                    break;
                }
                n++;
            }
            p++;
        }
    }
}
