import java.util.HashMap;
import java.util.Map;

public class p76 {
    static class Solution {
        public static boolean cover(Map<Integer, Integer> cnt, Map<Integer, Integer> base) {
            for (int k : base.keySet())
                if (!cnt.containsKey(k) || cnt.get(k) < base.get(k)) return false;
            return true;
        }

        public String minWindow(String s, String t) {
            int ls = s.length();
            int lt = t.length();
            if (ls < lt) return "";

            // 动态维护这个cnt, 表示当前窗口内的 所有字母个数， 包括在t中的和不在t中的，不能让任何一个为
            Map<Integer, Integer> cnt = new HashMap<>();
            // t中的字母数
            Map<Integer, Integer> base = new HashMap<>();
            int i = 0, j = lt - 1;
            for (int k = i; k <= j; k++) {
                base.put((int) t.charAt(k), base.getOrDefault((int) t.charAt(k), 0) + 1);
                cnt.put((int) s.charAt(k), cnt.getOrDefault((int) s.charAt(k), 0) + 1);
            }
            String ret = "";
            int min_len = Integer.MAX_VALUE;
            while (true) {
                if (cover(cnt, base) && min_len > j - i + 1) {
                    min_len = j - i + 1;
                    ret = s.substring(i, j + 1);
                    if (min_len == lt) return ret;
                }
                j++;
                if (j >= ls) break;
                int kj = s.charAt(j);
                cnt.put(kj, cnt.getOrDefault(kj, 0) + 1);
                while (j - i + 1 >= lt) {
                    int key = s.charAt(i);
                    if (!base.containsKey(key) || cnt.get(key) > base.get(key)) {
                        cnt.put((int) s.charAt(i), cnt.get((int) s.charAt(i)) - 1);
                        i++;
                    } else break;
                }
            }
            return ret;
        }
    }
}
