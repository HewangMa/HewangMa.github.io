import java.util.Arrays;

public class p124 {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     * int val;
     * TreeNode left;
     * TreeNode right;
     * TreeNode() {}
     * TreeNode(int val) { this.val = val; }
     * TreeNode(int val, TreeNode left, TreeNode right) {
     * this.val = val;
     * this.left = left;
     * this.right = right;
     * }
     * }
     */
    static class Solution {
        private static int[] maxPathSum_(ThreadNode root) {
            int[] ret = new int[3];
            // ret[0] 表示以root为端点的最长路径
            // ret[1] 表示不以root为端点的最长路径
//             ret[2] 表示有且仅有一个节点的最长路径，也就是所有子节点中的最大值
            Arrays.fill(ret, Integer.MIN_VALUE);
            if (root == null) return ret;// empty node

            if (root.left == null && root.right == null) {
                ret[0] = root.val;
//                ret[1] = 0;
                ret[2] = root.val;
            } else if (root.left == null) {
                int[] right_info = maxPathSum_(root.right);
                ret[0] = Math.max(root.val, right_info[0] + root.val);
                ret[1] = Math.max(right_info[0], right_info[1]);
                ret[2] = Math.max(right_info[2], root.val);
            } else if (root.right == null) {
                int[] left_info = maxPathSum_(root.left);
                ret[0] = Math.max(root.val, left_info[0] + root.val);
                ret[1] = Math.max(left_info[0], left_info[1]);
                ret[2] = Math.max(left_info[2], root.val);
            } else {
                int[] left_info = maxPathSum_(root.left);
                int[] right_info = maxPathSum_(root.right);
                ret[0] = Math.max(Math.max(left_info[0], right_info[0]), 0) + root.val;
                int left_max = Math.max(left_info[0], left_info[1]);
                int right_max = Math.max(right_info[0], right_info[1]);
                ret[1] = Math.max(left_max, right_max);
                ret[1] = Math.max(ret[1], left_info[0] + root.val + right_info[0]);
                ret[2] = Math.max(left_info[2], root.val);
                ret[2] = Math.max(right_info[2], ret[2]);
            }
            return ret;
        }

        public static int maxPathSum(ThreadNode root) {
            int[] root_info = maxPathSum_(root);
            int ret = Integer.MIN_VALUE;
            for (int i = 0; i < 3; i++) ret = Math.max(ret, root_info[i]);
            return ret;
        }
    }

    public static void main(String[] args) {
        ThreadNode right = new ThreadNode(-6, new ThreadNode(5), new ThreadNode(9));
        ThreadNode root = new ThreadNode(8, new ThreadNode(9), right);
        System.out.println(Solution.maxPathSum(root));
    }
}
