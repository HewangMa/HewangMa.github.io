public class p80 {
    private static class Solution {
        public static int removeDuplicates(int[] nums) {
            int i = 0;
            int k = 0; //赋值位
            int n = nums.length;
            while (i < n) {
                int tar = nums[i];
                // 对于每个tar，统计它的数量
                int cnt = 1;
                for (; i + cnt < n; cnt++)
                    if (nums[i + cnt] != tar) break;
                if (cnt == 1) {
                    nums[k++] = nums[i++];
                } else if (cnt == 2) {
                    nums[k++] = nums[i++];
                    nums[k++] = nums[i++];
                } else {
                    nums[k++] = nums[i++];
                    nums[k++] = nums[i++];
                    i += (cnt - 2);
                }
            }
            return k;
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1,1,2,2,3,3,4,4};
        System.out.println(Solution.removeDuplicates(nums));
        for (int one : nums) System.out.print(one + ", ");
    }
}
