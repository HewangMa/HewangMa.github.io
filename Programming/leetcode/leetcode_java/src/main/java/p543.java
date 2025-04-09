public class p543 {
    public static void main(String[] args) {

    }
}

class ThreadNode {
    int val;
    ThreadNode left;
    ThreadNode right;

    ThreadNode() {
    }

    ThreadNode(int val) {
        this.val = val;
    }

    ThreadNode(int val, ThreadNode left, ThreadNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solutionp543 {
    public int[] infoBinaryTree(ThreadNode root) {
        if (root == null) return new int[]{0, 0};
        if (root.left == null && root.right == null) return new int[]{0, 1};
        int[] ret = new int[2];
        int[] left_info = infoBinaryTree(root.left);
        int left_diam = left_info[0];
        int left_height = left_info[1];
        int[] right_info = infoBinaryTree(root.right);
        int right_diam = right_info[0];
        int right_height = right_info[1];
        ret[1] = Math.max(left_height, right_height) + 1;
        ret[0] = Math.max(left_height + right_height + 2, Math.max(left_diam, right_diam));
        return ret;
    }

    public int diameterOfBinaryTree(ThreadNode root) {
        int[]info =infoBinaryTree(root);
        return info[0];
    }
}