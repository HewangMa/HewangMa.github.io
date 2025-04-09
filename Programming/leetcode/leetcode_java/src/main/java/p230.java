import java.util.ArrayList;
import java.util.List;

public class p230 {
    public static void main(String[] args) {

    }
}

class Solutionp230 {
    List<Integer> nums;

    public void in_order(ThreadNode root) {
        if (root != null) {
            in_order(root.left);
            nums.add(root.val);
            in_order(root.right);
        }
    }

    public int kthSmallest(ThreadNode root, int k) {
        nums = new ArrayList<>();
        in_order(root);
        return nums.get(k-1);
    }
}
