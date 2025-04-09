import java.util.List;
import java.util.Stack;

public class p224 {
    static class Solution {
        public static int cal_sub(String sub) {
            System.out.print("now handling " + sub);
            int ret = 0;
            String[] parts = sub.split("\\+");
            for (String part : parts) {
                if (part.contains("-")) {
                    String[] sub_parts = part.split("-");
                    for (int i = 0; i < sub_parts.length; i++) {
                        String m_num = sub_parts[i];
                        int a = (m_num.isEmpty()) ? (0) : (Integer.parseInt(m_num));
                        if (i == 0) ret += a;
                        else ret -= a;
                    }
                } else ret += (part.isEmpty()) ? (0) : (Integer.parseInt(part));
            }
            System.out.println("got " + ret);
            return ret;
        }

        public static int calculate(String s) {
            StringBuilder sb = new StringBuilder(s);
            for (int i = sb.length() - 1; i >= 0; i--) if (sb.charAt(i) == ' ') sb.deleteCharAt(i);
            Stack<Character> sc = new Stack<>();
            for (int i = 0; i < sb.length(); i++) {
                char c = sb.charAt(i);
                if (c == ')') {
                    StringBuilder part = new StringBuilder();
                    while (!sc.empty() && sc.peek() != '(') {
                        part.insert(0, sc.peek());
                        sc.pop();
                    }
                    if (sc.peek() == '(') sc.pop();
                    int part_res = cal_sub(part.toString());
                    if (part_res < 0 && !sc.empty() && sc.peek() == '-') {
                        sc.pop();
                        sc.push('+');
                        part_res = -part_res;
                    }
                    String res_String = Integer.toString(part_res);
                    for (int j = 0; j < res_String.length(); j++) sc.push(res_String.charAt(j));
                } else sc.push(c);
            }
            StringBuilder part = new StringBuilder();
            while (!sc.empty()) {
                part.insert(0, sc.peek());
                sc.pop();
            }
            return cal_sub(part.toString());
        }
    }

    public static void main(String[] args) {
        System.out.println(Solution.calculate("-(-2)+4"));
    }
}
