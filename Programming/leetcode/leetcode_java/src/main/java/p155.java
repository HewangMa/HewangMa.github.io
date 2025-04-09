import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class p155 {

}

class MinStack {
    private List<Stack<Integer>> lst;

    public MinStack() {
        lst = new ArrayList<>();
    }

    public void push(int val) {
        if (lst.size() == 0) lst.add(new Stack<>());
        Stack<Integer> last = lst.get(lst.size() - 1);
        if (last.empty() || last.peek() >= val) last.push(val);
        else {
            Stack<Integer> temp = new Stack<>();
            temp.push(val);
            lst.add(temp);
        }
    }

    public void pop() {
        Stack<Integer> last = lst.get(lst.size() - 1);
        last.pop();
        if (last.size() <= 0) lst.remove(lst.size() - 1);
    }

    public int top() {
        Stack<Integer> last = lst.get(lst.size() - 1);
        return last.peek();
    }

    public int getMin() {
        int ret = Integer.MAX_VALUE;
        for (int i = 0; i < lst.size(); i++)
            ret = Math.min(ret, lst.get(i).peek());
        return ret;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
