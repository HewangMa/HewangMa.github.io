import java.util.ArrayList;
import java.util.List;

public class p113 {
}

class Solutionp113 {
    public List<List<Integer>> pathSum(ThreadNode root, int targetSum) {
        List<List<Integer>> ret = new ArrayList<>();
        ThreadNode p = root, r = null;
        List<ThreadNode> st = new ArrayList<>();
        int sum = 0;
        while (!st.isEmpty() || p != null) {
            if (p != null) {
                st.add(p);
                sum += p.val;
                p = p.left;
            } else {
                p = st.get(st.size() - 1);
                if (p.right != null && p.right != r) p = p.right;
                else {
                    if (p.left == null && p.right == null && sum == targetSum) {
                        List<Integer> path = new ArrayList<>();
                        for (ThreadNode t : st) path.add(t.val);
                        ret.add(path);
                    }
                    sum -= p.val;
                    st.remove(st.size() - 1);
                    r = p;
                    p = null;
                }
            }
        }
        return ret;
    }
}