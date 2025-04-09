import java.util.ArrayList;
import java.util.List;

public class p437 {
}

class Solutionp437 {
    public int pathSum(ThreadNode root, int targetSum) {
        int ret = 0;
        ThreadNode p = root, r = null;
        List<ThreadNode> st = new ArrayList<>();
        while (!st.isEmpty() || p != null) {
            if (p != null) {
                st.add(p);
                p = p.left;
            } else {
                p = st.get(st.size() - 1);
                if (p.right != null && p.right != r) p = p.right;
                else {
                    double sum = 0;
                    for (int i = st.size() - 1; i >= 0; i--) {
                        sum += st.get(i).val;
                        if (sum == targetSum) ret++;
                    }
                    st.remove(st.size() - 1);
                    r = p;
                    p = null;
                }
            }
        }
        return ret;
    }
}