import javax.swing.tree.TreeNode;
import java.util.ArrayList;
import java.util.List;

public class p173 {
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
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public class InThreadNode {
        int val;
        InThreadNode left;
        InThreadNode right;
        InThreadNode pre;
        InThreadNode post;


        InThreadNode() {
        }

        InThreadNode(int val) {
            this.val = val;
        }

        InThreadNode(int val, InThreadNode left, InThreadNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }

        InThreadNode(int val, InThreadNode left, InThreadNode right, InThreadNode pre, InThreadNode post) {
            this.val = val;
            this.left = left;
            this.right = right;
            this.pre = pre;
            this.post = post;
        }
    }

    static class BSTIterator {
        int curr_pos = -1;
        List<TreeNode> TN_list = new ArrayList<>();

        public void init_inorder(TreeNode root) {
            if (root == null) return;
            init_inorder(root.left);
            TN_list.add(root);
            init_inorder(root.right);
        }

        public BSTIterator(TreeNode root) {
            init_inorder(root);
        }

        public int next() {
            curr_pos++;
            return TN_list.get(curr_pos).val;
        }

        public boolean hasNext() {
            return curr_pos < TN_list.size() - 1;
        }
    }

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
}
