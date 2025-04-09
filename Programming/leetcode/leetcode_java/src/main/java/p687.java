public class p687 {
}

class Solutionp687 {
    public int[] longestUnivaluePath_(ThreadNode root) {
        int[] ret = new int[3];
        // ret[0]： 以root为端点的最长路径长度
        // ret[1]： 上述路径的共同值
        // ret[2]： 不以root为端点的最长路径长度
        if (root == null)
            return new int[]{0, 0, 0};
        if (root.left == null && root.right == null)
            return new int[]{1, root.val, 0};
        int[] left_info = longestUnivaluePath_(root.left);
        int[] right_info = longestUnivaluePath_(root.right);

        ret[0] = 1;
        ret[1] = root.val;
        int t1 = Math.max(left_info[0], right_info[0]);
        int t2 = Math.max(left_info[2], right_info[2]);
        ret[2] = Math.max(t1, t2);
        if (root.val == left_info[1])
            ret[0] = Math.max(ret[0], left_info[0] + 1);
        if (root.val == right_info[1])
            ret[0] = Math.max(ret[0], right_info[0] + 1);
        if (root.val == left_info[1] && root.val == right_info[1])
            ret[2] = Math.max(ret[2], left_info[0] + 1 + right_info[0]);
        return ret;
    }

    public int longestUnivaluePath(ThreadNode root) {
        if (root == null) return 0;
        int[] ans = longestUnivaluePath_(root);
        return Math.max(ans[0], ans[2]) - 1;
    }
}
