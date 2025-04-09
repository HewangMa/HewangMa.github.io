import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;

public class p740 {
    // leetcode.cn has the correct solution
    public static void main(String[] args) {
//        p740.test();
        Solutionp740 s = new Solutionp740();
        System.out.println(s.deleteAndEarn(new int[]{2, 2, 3, 3, 3, 4}));
    }

    public static void test() {
        HashMap<Integer, Integer> cnt = new HashMap<>();
        cnt.put(3, 1);
        cnt.put(2, 1);
        cnt.put(4, 1);
        cnt.remove(3);
        System.out.println(cnt);
    }
}

class Solutionp740 {
    public int maxOfHash(HashMap<Integer, Integer> cnt) {
        Set<Integer> st = cnt.keySet();
        Integer[] list = st.toArray(new Integer[0]);
        if (list.length == 0)
            return 0;
        int n = list[0];
        if (list.length == 1)
            return cnt.get(n) * n;

        HashMap<Integer, Integer> bcnt = new HashMap<>(cnt);
        // chose:
//        System.out.println(n);
        int count = cnt.get(n);
        cnt.remove(n + 1);
        cnt.remove(n);
        cnt.remove(n - 1);
//        System.out.println(cnt);
        // not chose:
        bcnt.remove(n);
        return Math.max(n * count + maxOfHash(cnt), maxOfHash(bcnt));
    }

    public int deleteAndEarn(int[] nums) {
        Arrays.sort(nums);
        int size = nums.length;
        // return size;
        HashMap<Integer, Integer> cnt = new HashMap<>();
        for (int num : nums) {
            if (cnt.containsKey(num))
                cnt.put(num, cnt.get(num) + 1);
            else
                cnt.put(num, 1);
        }
        // System.out.println(cnt.keySet());
        return maxOfHash(cnt);
        // List<Integer> list = new ArrayList<>();
        // for (int num : cnt.keySet())
        // list.add(num);
        // Collections.sort(list);
        // return maxOfHash(cnt);
        // return cnt.size();

        // int[] dp = new int[size]; // dp[i]表示在数字0-i中最大能获得的点数
        // dp[0] = list[0] * cnt[list[0]];
        // for (int i=1;i<list.size();i++){
        // if (cnt[list[i-1]]>cnt[list[i]]) extra
        // dp[list[i]]=Math.max(dp[list[i-1]],)
        // }
    }
}