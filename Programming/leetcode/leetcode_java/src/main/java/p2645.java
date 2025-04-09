public class p2645 {
    public static void main(String[] args) {
        Solutionp2645 s = new Solutionp2645();
        s.addMinimum("ababc");
    }
}

class Solutionp2645 {
    public int addMinimum(String word) {
        char charToReplace = 'x';
        StringBuilder sb = new StringBuilder(word);
        int idx = sb.indexOf("abc");
        while (idx != -1) {
            sb.setCharAt(idx, charToReplace);
            sb.setCharAt(idx + 1, charToReplace);
            sb.setCharAt(idx + 2, charToReplace);
            idx = sb.indexOf("abc");
        }
        int ret = 0;
        String[] list = {"ab", "bc", "ac"};
        for (String replace : list) {
            idx = sb.indexOf(replace);
            while (idx != -1) {
                sb.setCharAt(idx, charToReplace);
                sb.setCharAt(idx + 1, charToReplace);
                idx = sb.indexOf(replace);
                ret++;
            }
        }
        String[] list2 = {"a", "b", "c"};
        for (String replace : list2) {
            idx = sb.indexOf(replace);
            while (idx != -1) {
                sb.setCharAt(idx, charToReplace);
                idx = sb.indexOf(replace);
                ret += 2;
            }
        }
        return ret;
    }
}