import java.math.BigInteger;
import java.util.*;

public class p119 {
    private static boolean power_sum(long n) {
        int sum = digits_sum(n);
        if (sum == 1) return false;
//        System.out.println(sum);
        while (n % sum == 0) n /= sum;
        return n == 1;
    }

    public static void brute_force() {
        long p = 10;
        List<Long> power_sums = new ArrayList<>();
//        System.out.println(power_sum(614656));
        while (true) {
            if (power_sum(p)) {
                power_sums.add(p);
                System.out.println(power_sums.size() + ": " + p);
            }
            p++;
            if (power_sums.size() >= 30) break;
        }
        System.out.println(power_sums);
    }

    public static int digits_sum(long num) {
        int sum = 0;
        while (num > 0) {
            sum += (int) num % 10;
            num /= 10;
        }
        return sum;
    }

    public static BigInteger digits_sum(BigInteger num) {
        int sum = 0;
        char[] chars = num.toString().toCharArray();
        for (char c : chars) sum += Character.getNumericValue(c);
        return new BigInteger(Integer.toString(sum));
    }

    public static void find_base1() {
        int sum = 2;
        List<Long> power_sums = new ArrayList<>();
        while (true) {
            int e = 2;
            long p = (long) Math.pow(sum, e);
            boolean find_one = false;
            while (!find_one && e <= 20) {
                if (digits_sum(p) == sum) {
                    find_one = true;
                    power_sums.add(p);
                }
                e++;
                p = (long) Math.pow(sum, e);
            }
            sum++;
            if (sum > 40) break;
        }
        Collections.sort(power_sums);
        for (int i = 0; i < power_sums.size(); i++)
            System.out.println((i + 1) + ": " + power_sums.get(i));

    }

    public static void find_base2() {
        List<List<BigInteger>> matric = new ArrayList<>();
        //初始化base
        for (int sum = 2; sum < 100; sum++) {
            List<BigInteger> temp = new ArrayList<>();
            temp.add(new BigInteger(Integer.toString(sum)));
            temp.add(new BigInteger("1"));
            temp.add(new BigInteger(Integer.toString(sum)));
            matric.add(temp);
        }
        BigInteger up_bound = new BigInteger("10");
        List<BigInteger> power_sums = new ArrayList<>();
        int idx = 0;
        Scanner scanner = new Scanner(System.in);
        BigInteger loop_max = new BigInteger(String.valueOf(up_bound));
        BigInteger found_max_base = new BigInteger("2");
        while (power_sums.size() < 30) {
////            暂停执行
//            System.out.print("请输入:");
//            int pause = scanner.nextByte();
////            找到下一个base
//            System.out.println("up_bound: " + up_bound);
////            打印看看
//            int print_cnt = 0;
//            for (List<BigInteger> t : matric) {
//                System.out.print(t + ", ");
//                print_cnt++;
//                if (print_cnt % 8 == 0) System.out.println();
//            }
//            System.out.println();
            while (matric.get(idx).get(2).compareTo(up_bound) >= 0) {
                idx = (idx + 1) % matric.size();
                if (idx == 0) up_bound = loop_max;
            }
            BigInteger base = matric.get(idx).get(0);
            BigInteger e = matric.get(idx).get(1);
            while (true) {
                e = e.add(BigInteger.ONE);
                BigInteger pow = base.pow(Integer.parseInt(e.toString()));
                matric.get(idx).set(2, pow);
                matric.get(idx).set(1, e);
                if (base.equals(digits_sum(pow))) {
                    if (base.compareTo(found_max_base) > 0) {
                        System.out.println("found_max_base: " + found_max_base);
                        found_max_base = base;
                    }
                    power_sums.add(pow);
                    up_bound = pow;
                    break;
                }
                if (pow.compareTo(up_bound) > 0) {
                    if (loop_max.compareTo(pow) < 0) loop_max = pow;
                    break;
                }
            }
//            System.out.println(up_bound);
        }
        Collections.sort(power_sums);
        System.out.println("power_sums: ");
        for (int i = 0; i < power_sums.size(); i++)
            System.out.println((i + 1) + ": " + power_sums.get(i));
    }

    /*
    1: 81
    2: 512
    3: 2401
    4: 4913
    5: 5832
    6: 17576
    7: 19683
    8: 234256
    9: 390625
    10: 614656
    11: 1679616
    12: 17210368
    13: 34012224
    14: 52521875
    15: 60466176
    16: 205962976
    17: 612220032
     */
    public static void main(String[] args) {
//        brute_force();
        find_base2();
//        System.out.println(digits_sum(new BigInteger("1325")));
    }
}
