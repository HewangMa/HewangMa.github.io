import java.util.Objects;
import java.util.Stack;

public class p71 {
    static class Solution {
        public static String get_next(String path, int i) {
            if (i >= path.length()) return "";
            char c = path.charAt(i);
            if (c == '/') return "/";
            else return c + get_next(path, i + 1);
        }

        public static String simplifyPath(String path) {
            path = path + '/';
            Stack<String> st = new Stack<>();
            int i = 0;
            String next = get_next(path, i);
            while (!next.isEmpty()) {
                System.out.println(next);
                char begin_char = next.charAt(0);
                if (begin_char == '.') {
                    // 根据长度做不同操作
                    if (next.length() == 2) {
                    } // 当前目录 不操作
                    else if (next.length() == 3 && next.charAt(1) == '.') {
                        if (!st.empty()) st.pop(); // 上一级目录
                    } else st.push(next);// 文件名 压入
                } else if (begin_char != '/') st.push(next);
                i += next.length();
                next = get_next(path, i);
            }
            Stack<String> temp = new Stack<>();
            while (!st.empty()) {
                temp.push(st.peek());
                st.pop();
            }
            StringBuilder ret = new StringBuilder();
            while (!temp.empty()) {
                ret.append(temp.peek());
                temp.pop();
            }
            if (ret.length() == 0 || ret.charAt(0) != '/') ret.insert(0, '/');
            if (ret.length() > 1 && ret.charAt(ret.length() - 1) == '/') ret.deleteCharAt(ret.length() - 1);
            return ret.toString();
        }
    }

    public static void main(String[] args) {
        String path = "/../..ga/b/.f..d/..../e.baaeeh./.a";
        System.out.println(Solution.simplifyPath(path));
    }
}
