import java.util.Arrays;

public class p1944 {
}

class Solutionp1944 {
    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        int[] ret = new int[n];
        Arrays.fill(ret, 0);
        // find the increasing sequence from myself;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i + 1; j < n; j++) {
                if (heights[j] > cur) {
                    ret[i]++;
                    cur = heights[j];
                    if (cur > heights[i]) break;
                }
            }
        }
        return ret;
    }
}