import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class p129 {
    public static int facs(int k) {
        StringBuilder r = new StringBuilder();
        for (int i = 0; i < k; i++) r.append(1);
        BigInteger R = new BigInteger(r.toString());
        BigInteger i = new BigInteger(Integer.toString(3));
        List<Integer> facs = new ArrayList<>();
        while (R.compareTo(i) > 0) {
            if (R.remainder(i).equals(BigInteger.ZERO)) {
                R = R.divide(i);
                facs.add(i.intValue());
            } else i = i.add(BigInteger.ONE);
        }
        if (!R.equals(BigInteger.ONE)) facs.add(R.intValue());
        System.out.println("for R(k) = " + r + ", facs are: " + facs);
        return 0;
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

    public static int brute_force() {
        int test_size = 1000000;
        for (int n = test_size; ; n++) {
            if (n % 2 == 0 || n % 5 == 0) continue;
            int An = findLeastDivisibleRepunit(n);
            if (An > test_size / 2)
                System.out.println("for n = " + n + ", An = " + An);
            if (An > test_size) {
                System.out.println("the n first exceeds " + test_size + " is: " + n);
                break;
            }
        }
        return 1;
    }

    public static int test() {
        StringBuilder r = new StringBuilder();
        BigInteger T = new BigInteger("1001");
        int n = 17;
        BigInteger N = new BigInteger(Integer.toString(n));
        for (int k = 0; ; k++) {
            r.append(1);
            BigInteger R = new BigInteger(r.toString());
            if (R.remainder(N).equals(BigInteger.ZERO)) {
                // && !R.remainder(T).equals(BigInteger.ZERO)
                System.out.println(R);
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        // 思路是将 R(k) 分解质因数，找出其中最小的不能用 R(k-) 表示
//        facs(100);
        brute_force();
//        test();
    }

}
