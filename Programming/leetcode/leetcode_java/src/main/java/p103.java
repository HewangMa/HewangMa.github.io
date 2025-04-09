import javax.swing.tree.TreeNode;
import java.util.*;

public class p103 {
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

    class Solution {
        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
            List<List<Integer>> ret = new ArrayList<>();
            if (root == null) return ret;
            Queue<TreeNode> q = new LinkedList<>();
            q.offer(root);
            int level_num = 1;
            int depth = 0;
            while (!q.isEmpty()) {
                int next_level_num = 0;
                List<Integer> level = new ArrayList<>();
                while (level_num > 0) {
                    TreeNode head = q.poll();
                    assert head != null;
                    if (head.left != null) {
                        next_level_num++;
                        q.offer(head.left);
                    }
                    if (head.right != null) {
                        next_level_num++;
                        q.offer(head.right);
                    }
                    level.add(head.val);
                    level_num--;
                }
                level_num = next_level_num;
                if (depth % 2 == 1) Collections.reverse(level);
                ret.add(level);
                depth++;
            }
            return ret;
        }
    }
}
