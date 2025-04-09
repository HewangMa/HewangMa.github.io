import java.util.ArrayList;
import java.util.List;

public class p228 {
    class Solution {
        public List<String> summaryRanges(int[] nums) {
            int i = 0;
            int n = nums.length;
            List<String> ret = new ArrayList<>();
            if (n == 0) return ret;
            int start = nums[0];
            int end = nums[0];
            while (i < n) {
                if (i < n - 1 && nums[i + 1] == nums[i] + 1) {
                    end++;
                    i++;
                } else {
                    // run into a gap
                    StringBuilder t = new StringBuilder();
                    if (start == end) {
                        t.append(start);
                    } else {
                        t.append(start);
                        t.append("->");
                        t.append(end);
                    }
                    ret.add(t.toString());
                    i++;
                    if (i >= n) break;
                    start = nums[i];
                    end = nums[i];
                }
            }
            return ret;
        }
    }

    public static void main(String[] args) {
//        List<S>
//        System.out.println();
    }
}
