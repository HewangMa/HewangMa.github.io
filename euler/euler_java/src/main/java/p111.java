import sun.text.normalizer.UCharacter;

import java.net.Inet4Address;
import java.util.*;

public class p111 {
    public static Boolean prime(long n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    public static void main(String[] args) {
//        System.out.println(prime(2000000000005l));
//        StringBuilder sb = new StringBuilder("111");
//        sb.insert(5, 2);
//        System.out.println(sb);
        long[] s = new long[10];
        Arrays.fill(s, 0);
        for (int repeat_digit = 0; repeat_digit <= 9; repeat_digit++) {
            Set<Long> nums = generate9(repeat_digit);
            if (nums.isEmpty()) nums = generate8(repeat_digit);
            if (nums.isEmpty()) System.out.println("\n\n there is also no eight ans \n\n");
            System.out.println("repeat of: " + repeat_digit);
            int print_cnt = 0;
            for (long num : nums) {
                s[repeat_digit] += num;
                System.out.print(num + ", ");
                print_cnt++;
                if (print_cnt % 5 == 0) System.out.println();
            }
            System.out.println();
        }
        long all_s = 0;
        for (long sum : s) {
            all_s += sum;
            System.out.println(sum + ", ");
        }
        System.out.println(all_s);
    }

    public static void brute_force() {
        long p = 1001l;
//        long origin_p = p;
        long up_bound = (p - 1) * 10 - 1;
        int[][] cnt = new int[10][10];
        // cnt[i][j] is the number of primes where digit i appears j times;
        for (int[] ints : cnt) Arrays.fill(ints, 0);
        // easier way to initialize a 2dArray
//        int[] M = new int[10];
//        int[] N = new int[10];
//        int[] S = new int[10];
        int[] digit_num = new int[10];
//        Arrays.fill(M, 0);
//        Arrays.fill(N, 0);
//        Arrays.fill(S, 0);
//        int print_cnt = 0;
//        System.out.println("primes: ");
        while (p <= up_bound) {
            if (prime(p)) {
//                System.out.print(p + ", ");
//                print_cnt++;
//                if (print_cnt % 5 == 0)
//                    System.out.println();
                long t = p;
                Arrays.fill(digit_num, 0);
                while (t > 0) {
                    int digit = (int) (t % 10);
                    digit_num[digit]++;
                    t /= 10;
                }
                for (int digit = 0; digit <= 9; digit++)
                    cnt[digit][digit_num[digit]]++;
            }
            p += 2;
            if (p % 1000001 == 0) System.out.println("tring on p = " + p);
        }
        System.out.println();
        for (int i = 0; i < 10; i++) {
            System.out.print(i + ": ");
            for (int j = 0; j < 10; j++)
                System.out.print(cnt[i][j] + ", ");
            System.out.println();
        }
    }

//    public static Set<Long> generate10(int repeat_digit) {
//        List<Long> ret = new ArrayList<>();
//        StringBuilder sb = new StringBuilder();
//        for (int i = 0; i < 10; i++) sb.append(repeat_digit);
//        long temp = Long.parseLong(sb.toString());
//        if (prime(temp)) ret.add(temp);
//        return ret;
//    }

    public static Set<Long> generate9(int repeat_digit) {
        Set<Long> ret = new HashSet<>();
        // proceed: return two sets of result.
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 9; i++) sb.append(repeat_digit);
        // 10 digits prime will only possible to have 8 or 9 repeated digits;
        //if 9, add one;
        for (int add_digit = 0; add_digit <= 9; add_digit++) {
            if (add_digit == repeat_digit) continue;
            for (int add_pos = 0; add_pos <= 9; add_pos++) {
                StringBuilder nsb = new StringBuilder(sb);
                nsb.insert(add_pos, add_digit);
                long temp = Long.parseLong(nsb.toString());
                if (temp < 1000000000l) continue;
                if (prime(temp)) ret.add(temp);
            }
        }
        return ret;
    }

    public static Set<Long> generate8(int repeat_digit) {
        Set<Long> ret = new HashSet<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 8; i++) sb.append(repeat_digit);
        for (int add_digit1 = 0; add_digit1 <= 9; add_digit1++) {
            if (add_digit1 == repeat_digit) continue;
            for (int add_digit2 = 0; add_digit2 <= 9; add_digit2++) {
                if (add_digit2 == repeat_digit) continue;
                for (int add_pos1 = 0; add_pos1 <= 8; add_pos1++) {
                    for (int add_pos2 = 0; add_pos2 <= 9; add_pos2++) {
                        StringBuilder nsb = new StringBuilder(sb);
                        nsb.insert(add_pos1, add_digit1);
                        nsb.insert(add_pos2, add_digit2);
                        long temp = Long.parseLong(nsb.toString());
                        if (temp < 1000000000l) continue;
                        if (prime(temp)) ret.add(temp);
                    }
                }
            }
        }
        return ret;
    }

    public static List<Long> generate3(int repeat_digit) {
        List<Long> ret = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 3; i++) sb.append(repeat_digit);
        for (int add_digit = 0; add_digit <= 9; add_digit++) {
            if (add_digit == repeat_digit) continue;
            for (int add_pos = 0; add_pos <= 3; add_pos++) {
                StringBuilder nsb = new StringBuilder(sb);
                nsb.insert(add_pos, add_digit);
                long temp = Long.parseLong(nsb.toString());
                if (temp < 1000l) continue;
                if (prime(temp)) ret.add(temp);
            }
        }
        return ret;
    }

    public static List<Long> generate2(int repeat_digit) {
        List<Long> ret = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 2; i++) sb.append(repeat_digit);
        for (int add_digit1 = 0; add_digit1 <= 9; add_digit1++) {
            if (add_digit1 == repeat_digit) continue;
            for (int add_digit2 = add_digit1 + 1; add_digit2 <= 9; add_digit2++) {
                if (add_digit2 == repeat_digit) continue;
                for (int add_pos1 = 0; add_pos1 <= 2; add_pos1++) {
                    for (int add_pos2 = 0; add_pos2 <= 3; add_pos2++) {
                        StringBuilder nsb = new StringBuilder(sb);
                        nsb.insert(add_pos1, add_digit1);
                        nsb.insert(add_pos2, add_digit2);
                        long temp = Long.parseLong(nsb.toString());
                        if (temp < 1000l) continue;
                        if (prime(temp)) ret.add(temp);
                    }
                }
            }
        }
        return ret;
    }

    public static void testStringBuilder() {
        StringBuilder test_sb = new StringBuilder();
        for (int i = 0; i < 9; i++)
            test_sb.append(1);
//        test_sb.insert(0, 9);
        StringBuilder nsb = new StringBuilder(test_sb);
        nsb.insert(3, 9);
        System.out.println(nsb);
        System.out.println(test_sb);
    }
}
