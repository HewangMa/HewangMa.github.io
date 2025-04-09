import com.sun.java.swing.plaf.windows.WindowsTextAreaUI;

import java.util.*;

public class p30 {
    static class Solution1 {
        private static StringBuilder curs = new StringBuilder();
        private static Set<Integer> idxs = new HashSet<>();
        private static Map<Integer, Boolean> idx_inserted = new HashMap<>();

        public static void back_tracking(String s, String[] words) {
            String curss = curs.toString();
            if (!s.contains(curss)) return;
            else if (idx_inserted.size() >= words.length) {
                idxs.add(s.indexOf(curss));
                int index = s.indexOf(curss);
                while (index != -1) {
                    idxs.add(index);
                    index = s.indexOf(curss, index + 1);
                }
            }
            for (int i = 0; i < words.length; i++) {
                if (!idx_inserted.containsKey(i)) {
                    int cur_len = curs.length();
                    curs.append(words[i]);
                    idx_inserted.put(i, true);
                    back_tracking(s, words);
                    curs.delete(cur_len, curs.length());
                    idx_inserted.remove(i);
                }
            }
        }

        public static List<Integer> findSubstring(String s, String[] words) {
            back_tracking(s, words);
            return new ArrayList<>(idxs);
        }
    }

    static class Solution2 {
        public static List<Integer> findSubstring(String s, String[] words) {
            Map<String, Integer> words_count = new HashMap<>();
            for (String w : words)
                if (words_count.containsKey(w)) words_count.put(w, words_count.get(w) + 1);
                else words_count.put(w, 1);
            List<Integer> ret = new ArrayList<>();
            int word_length = words[0].length();
            int word_num = words.length;
            for (int i = 0; i < s.length(); i ++) {
                boolean tag = true;
                Map<String, Integer> remain = new HashMap<>(words_count);
                for (int j = 0; j < word_num; j++) {
                    String sub_str = s.substring(i + j * word_length, i + (j + 1) * word_length);
                    if (!remain.containsKey(sub_str)) {
                        tag = false;
                        break;
                    } else {
                        remain.put(sub_str, remain.get(sub_str) - 1);
                        if (remain.get(sub_str) < 0) {
                            tag = false;
                            break;
                        }
                    }
                }
                for (String key : remain.keySet())
                    if (remain.get(key) > 0) {
                        tag = false;
                        break;
                    }
                if (tag) ret.add(i);
                if (i + word_num * word_length >= s.length()) break;
            }
            return ret;
        }
    }

    public static void main(String[] args) {
        String[] test_words = new String[]{"foo", "bar"};
        System.out.println(Solution2.findSubstring("barfoothefoobarman", test_words));
    }
}
