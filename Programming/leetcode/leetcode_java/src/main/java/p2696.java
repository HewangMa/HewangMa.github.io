public class p2696 {
    public static void main(String[] args) {
        Solutionp2696 s = new Solutionp2696();
        System.out.println(s.minLength("ABFCACDB"));

    }
}

class Solutionp2696 {
    public int minLength(String s) {
        StringBuilder sb = new StringBuilder(s);
        int idx1 = sb.indexOf("AB");
        int idx2 = sb.indexOf("CD");
        while (idx1 != -1 || idx2 != -1) {
            if (idx1 > idx2) sb.delete(idx1, idx1 + 2);
            else sb.delete(idx2, idx2 + 2);
//            System.out.println(sb);
            idx1 = sb.indexOf("AB");
            idx2 = sb.indexOf("CD");
        }
        return sb.length();
    }
}