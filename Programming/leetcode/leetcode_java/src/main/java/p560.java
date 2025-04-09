public class p560 {
    public static void main(String[] args) {

    }
}

class Solutionp560 {
    public int subarraySum0(int[] nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++)
            nums[i] += 1001;
        int curSum = nums[0];
        int curLen = 1;
        int ret = 0;
        while (left <= n) {
            while (curSum < k) {
                right++;
                curSum += nums[right];
            }
            if (curSum == k) {
                ret++;
                curSum -= nums[left];
                left++;
                right++;
                curSum += nums[right];
            }
        }
        return 0;
    }

    public int subarraySum1(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n];// dp[i] 表示以nums[i]为结尾的子数组中有多少答案；
        if (nums[0] == k)
            dp[0] = 1;
        else
            dp[0] = 0;
//        for (int i = 1; i < n; i++) {
//            if
//        }
        return 0;
    }

    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] preSum = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) preSum[i] = nums[i];
            else preSum[i] = preSum[i - 1] + nums[i];
        }
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (preSum[j] - preSum[i] + nums[i] == k) ret++;
        return ret;
    }
}
