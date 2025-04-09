public class p105 {
    public static void main(String[] args) {

    }
}

class Solutionp105 {
    public ThreadNode buildTree_(int[] preorder, int pre_left, int pre_right, int[] inorder, int in_left, int in_right) {
        if (pre_left == pre_right)
            return new ThreadNode(preorder[pre_left]);
        for (int i = in_left; i <= in_right; i++) {
            if (inorder[i] == preorder[pre_left]) {
                int left_num = i - in_left;
                ThreadNode left = buildTree_(preorder, pre_left + 1, pre_left + left_num, inorder, in_left, i - 1);
                ThreadNode right = buildTree_(preorder, pre_left + left_num + 1, pre_right, inorder, i + 1, in_right);
                return new ThreadNode(inorder[i], left, right);
            }
        }
        return null;
    }

    public ThreadNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        return buildTree_(preorder, 0, n - 1, inorder, 0, n - 1);
    }
}