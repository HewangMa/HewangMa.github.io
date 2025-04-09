import java.util.Arrays;

public class p274 {
    static class Solution {
        public static int hIndex(int[] citations) {
            int n = citations.length;
            int[] H = new int[1002];
            Arrays.fill(H, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= citations[i]; j++) H[j]++;
            }
            int ret = 0;
            for (int i = 0; i < H.length; i++) {
                if (H[i] >= i) ret = i;
            }
            return ret;
        }
    }

    public static void main(String[] args) {
        int[] H = new int[]{1,3,1};
        System.out.println(Solution.hIndex(H));
    }
}
