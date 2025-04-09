import org.w3c.dom.ls.LSException;

import java.util.*;

public class p118 {
    private static List<StringBuilder> permuts;

    private static boolean prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }

    private static void find_permutations(StringBuilder digits) {
        if (digits.length() >= 9) {
            permuts.add(new StringBuilder(digits));
            return;
        }
        for (int i = 1; i <= 9; i++) {
            if (digits.indexOf(Integer.toString(i)) < 0) {
                digits.append(i);
                find_permutations(digits);
                digits.deleteCharAt(digits.length() - 1);
            }
        }
    }

    private static Set<List<Integer>> prime_sets;

    private static void seperate_primes(String rest_digits, List<Integer> primes) {
        if (rest_digits.length() <= 0) {
            List<Integer> copy = new ArrayList<>(primes);
            Collections.sort(copy);
            prime_sets.add(copy);
        }
        for (int len = 1; len <= rest_digits.length(); len++) {
            int seperate_num = Integer.parseInt(rest_digits.substring(0, len));
            if (prime(seperate_num)) {
                primes.add(seperate_num);
                seperate_primes(rest_digits.substring(len), primes);
                primes.remove(primes.size() - 1);
            }
        }
    }

    public static void main(String[] args) {
        permuts = new ArrayList<>();
        find_permutations(new StringBuilder());
        prime_sets = new HashSet<>();
        for (StringBuilder per : permuts)
            seperate_primes(per.toString(), new ArrayList<>());
        System.out.println(prime_sets.size());
    }
}
