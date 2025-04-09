import java.util.LinkedList;
import java.util.List;

public class p122_solved_solwly {
    private static int binary_find_m(int k) {
        String binary = Integer.toBinaryString(k);
        int cnt = 0;
        for (char c : binary.toCharArray()) if (c == '1') cnt++;
        return binary.length() + cnt - 2;
    }

    private static int three_find_m(int k) {
        if (k == 1) return 0;
        if (k == 2) return 1;
        int ret = 2;
        return 0;
    }

    private static boolean prime(int p) {
        if (p < 2) return false;
        for (int i = 2; i <= Math.sqrt(p); i++)
            if (p % i == 0) return false;
        return true;
    }

    private static int factors() {
        // 不完全对
        int[] steps = new int[202];
        steps[1] = 0;
        steps[2] = 1;
        steps[3] = 2;
        int sum = 3;
        for (int i = 4; i <= 200; i++) {
            steps[i] = Integer.MAX_VALUE;
            for (int fac = 2; fac <= (int) Math.sqrt(i); fac++) {
                if (i % fac == 0) steps[i] = Math.min(steps[i], steps[fac] + steps[i / fac]);
                else {
                    int rfac = i / fac;
                    if (i - fac * rfac != 1) {
                        steps[i] = Math.min(steps[i], steps[fac] + steps[rfac] + steps[i - fac * rfac]);
                        System.out.println("wrong!!!!");
                    } else steps[i] = Math.min(steps[i], steps[fac] + steps[rfac] + 1);
                }
//                System.out.println(fac + ", " + rfac + ", " + steps[i]);
            }
//            if (steps[i] == 1) break;
            sum += steps[i];
        }
//        return sum;
        for (int j = 1; j <= 200; j++) {
            System.out.print(j + ": " + steps[j] + ";  ");
            if (j % 5 == 0) System.out.println();
        }
        return sum;
    }

    private static void myTest() {
        // 张锦涛贡献
        int sum = 0;
        for (int i = 1; i < 201; i++) {
            int[] ans = {2147483647};
            List<Integer> list = new LinkedList<>();
            list.add(1);
            lestMutiple(i, list, 1, 0, ans);
            System.out.println("k=" + i + ":" + ans[0]);
            sum += ans[0];
//            System.out.println(sum);
        }
        System.out.println(sum);
    }

    private static void lestMutiple(int k, List<Integer> list, int cur, int cnt, int[] ans) {
        // 张锦涛贡献
        if (cnt > 11) return;
        if (cur > k) return;
        else if (cur == k) {
            ans[0] = Math.min(cnt, ans[0]);
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            if (cur + list.get(i) <= k) {
                cur += list.get(i);
                list.add(cur);
                cnt++;
                lestMutiple(k, list, cur, cnt, ans);
                cnt--;
                list.remove(list.size() - 1);
                cur -= list.get(i);
            }
        }
    }

    public static void main(String[] args) {
//        for (int i = 0; i < 100; i++)
//            if (prime(i)) System.out.print(i + ", ");
//        System.out.println(factors());
        myTest();
//        for (int i = 0; i < 100; i++) {
//            if (prime(i)) System.out.println(i + ": " + binary_find_m(i));
//        }
//        System.out.println(binary_find_m(15));
    }
}
