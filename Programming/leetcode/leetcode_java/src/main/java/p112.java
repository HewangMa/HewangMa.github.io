import java.util.Stack;

public class p112 {
}

class Solutionp112 {
    public boolean hasPathSum(ThreadNode root, int targetSum) {
        if (root == null) return false;
        ThreadNode p = root, r = null;
        Stack<ThreadNode> st = new Stack<>();
        int sum = 0;
        while (!st.empty() || p != null) {
            if (p != null) {
                st.push(p);
                sum += p.val;
                p = p.left;
            } else {
                p = st.peek();
                if (p.right != null && p.right != r) p = p.right;
                else {
                    //visit(p)
                    p = st.peek();
                    if (p.left == null && p.right == null && sum == targetSum) return true;
                    sum -= p.val;
                    st.pop();
                    r = p;
                    p = null;
                }
            }
        }
        return false;
    }
}