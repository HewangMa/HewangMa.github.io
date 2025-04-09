public class p238 {
    public static void main(String[] args) {
        int[] p = new Solutionp238().productExceptSelf(new int[]{-1, 1, 0, -3, 3});
        for (int n : p) System.out.println(n + ",");
    }
}

class Solutionp238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] preProc = new int[n];
        int[] postProc = new int[n];
        int p = 1;
        for (int i = 0; i <= n - 2; i++) {
            p *= nums[i];
            preProc[i] = p;
        }
        p = 1;
        for (int i = n - 1; i >= 1; i--) {
            p *= nums[i];
            postProc[i] = p;
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) ans[i] = postProc[i + 1];
            else if (i == n - 1) ans[i] = preProc[i - 1];
            else ans[i] = preProc[i - 1] * postProc[i + 1];
        }
        return ans;
    }
}