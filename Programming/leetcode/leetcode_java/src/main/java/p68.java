import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p68 {
    static class Solution {
        public static List<String> get_line(String[] words, int start, int maxWidth) {
            List<String> ret = new ArrayList<>();
            int cur_length = 0;// 当前选取字符串的长度和 不包括空格
            while (start < words.length) {
                if (cur_length + ret.size() + words[start].length() > maxWidth) return ret;
                ret.add(words[start]);
                cur_length += words[start].length();
                start++;
            }
            return ret;
        }

        public static StringBuilder adjust_line(List<String> line, int maxWidth) {
            StringBuilder ret = new StringBuilder();
            int rest = maxWidth;
            for (String s : line) rest -= s.length();
            int size = line.size();
            if (size == 1) {
                ret.append(line.get(0));
                for (int j = 0; j < rest; j++)
                    ret.append(' ');
            } else {
                int small = rest / (size - 1);
                List<Integer> add = new ArrayList<>();
                for (int i = 0; i < size - 1; i++) add.add(small);
                rest -= (small * (size - 1));
                for (int i = 0; i < rest; i++) add.set(i, add.get(i) + 1);
                for (int i = 0; i < size; i++) {
                    ret.append(line.get(i));
                    if (i != size - 1)
                        for (int j = 0; j < add.get(i); j++) ret.append(' ');
                }
            }
            return ret;
        }

        public static List<String> fullJustify(String[] words, int maxWidth) {
            List<String> ret = new ArrayList<>();
            int i = 0;
            while (true) {
                List<String> line = get_line(words, i, maxWidth);
                StringBuilder a_line = adjust_line(line, maxWidth);
                i += line.size();
                if (i >= words.length) {
                    int j = 0, k = 0;
                    while (j < a_line.length()) {
                        if (j < a_line.length() - 1 && a_line.charAt(j) == a_line.charAt(j + 1) && a_line.charAt(j) == ' ') {
                            j++;
                        } else {
                            a_line.setCharAt(k, a_line.charAt(j));
                            j++;
                            k++;
                        }
                    }
                    while (k < a_line.length()) a_line.setCharAt(k++, ' ');
                    ret.add(a_line.toString());
                    break;
                }
                ret.add(a_line.toString());
            }
            for (String s : ret) System.out.println(s);
            return ret;
        }
    }

    public static void main(String[] args) {
        String[] test = new String[]{"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country"};
        Solution.fullJustify(test, 16);
    }
}
