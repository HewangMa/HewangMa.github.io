import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class p57 {
    static class Solution {
        private static void ret_print(int[][] ret) {
            for (int[] ints : ret) System.out.print("[" + ints[0] + ", " + ints[1] + "],  ");
            System.out.println();
        }

        public static int[][] insert(int[][] intervals, int[] newInterval) {
            int n = intervals.length;
            if (n == 0) return new int[][]{new int[]{newInterval[0], newInterval[1]}};
            int p = 0;
            for (int[] iv : intervals) {
                if (iv[1] < newInterval[0] || newInterval[1] < iv[0]) p++;
            }
            int[][] ret = new int[p + 1][2];
            int i = 0, k = 0;
            while (i < n) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                if (r < newInterval[0]) {
                    ret[k][0] = l;
                    ret[k][1] = r;
                    i++;
                    k++;
                } else break;
            }
            while (i < n) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                if (newInterval[1] < l) {
                    break;
                } else {
                    newInterval[0] = Math.min(newInterval[0], l);
                    newInterval[1] = Math.max(newInterval[1], r);
                }
                i++;
            }
            ret[k][0] = newInterval[0];
            ret[k][1] = newInterval[1];
            k++;
            while (i < n) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                if (newInterval[1] < l) {
                    ret[k][0] = l;
                    ret[k][1] = r;
                    i++;
                    k++;
                } else break;
            }
//            ret_print(ret);
            return ret;
        }
    }

    public static void main(String[] args) {
        int[][] intervals = new int[5][2];
        intervals[0][0] = 1;
        intervals[0][1] = 2;
        intervals[1][0] = 3;
        intervals[1][1] = 5;
        intervals[2][0] = 6;
        intervals[2][1] = 7;
        intervals[3][0] = 8;
        intervals[3][1] = 10;
        intervals[4][0] = 12;
        intervals[4][1] = 16;

        Solution.insert(intervals, new int[]{4, 8});
    }
}
