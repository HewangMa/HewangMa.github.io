#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

class DinnerPlates1 {
   public:
    int counts;
    int left;
    int right;
    int capacity;
    vector<int> tops;
    vector<vector<int>> sts;
    DinnerPlates1(int capacity) {
        this->capacity = capacity;
        counts = 200001;
        // cout<<counts<<endl;
        left = 0;
        right = counts - 1;
        tops = vector<int>(counts, 0);
        sts = vector<vector<int>>(counts, vector<int>(capacity));
        // cout<<"one##"<<endl;
    }
    void push(int val) {
        int i = min(left, right);
        if (i < 0)
            i = 0;
        // cout<<capacity<<endl;
        while (i < counts && tops[i] == capacity)
            i++;
        if (i == counts) {
            cout << "full" << endl;
            return;
        }
        left = i;
        sts[i][tops[i]++] = val;
    }
    int pop() {
        int i = max(left, right);
        // int i=counts-1;
        while (i >= 0 && tops[i] == 0)
            i--;
        if (i == -1)
            return -1;
        right = i;
        tops[i]--;
        if (tops[i] == 0)
            left--;
        return sts[i][tops[i]];
    }
    int popAtStack(int index) {
        if (index < 0 || index >= counts)
            return -1;
        if (tops[index] == 0)
            return -1;
        left = min(left, index);
        tops[index]--;
        return sts[index][tops[index]];
    }
};

class DinnerPlates2 {
   public:
    int capacity;
    int last_idx;
    priority_queue<int, vector<int>, greater<int>> available;
    vector<stack<int>> sts;
    DinnerPlates2(int capacity) {
        this->last_idx = 0;
        this->capacity = capacity;
        available.push(0);
        sts.emplace_back(stack<int>());
    }

    void push(int val) {
        int pos = available.top();
        if (pos >= sts.size())
            return;
        sts[pos].push(val);
        if (pos > last_idx)
            last_idx = pos;
        int size = sts[pos].size();
        if (size >= capacity)
            available.pop();
        if (available.size() == 0) {
            sts.emplace_back(stack<int>());
            available.push(sts.size() - 1);
        }
    }

    int pop() { return popAtStack(last_idx); }

    int popAtStack(int index) {
        // cout << "trying to pop at " << index << " where last_idx is "
        //      << last_idx << endl;
        if (index > last_idx || sts[index].empty())
            return -1;
        int ret = sts[index].top();
        int size = sts[index].size();
        if (size == capacity)
            available.push(index);
        sts[index].pop();
        while (last_idx >= 0 && sts[last_idx].empty()) {
            sts.pop_back();
            last_idx--;
        }
        return ret;
    }

    void printStack(stack<int> originalStack) {
        stack<int> tempStack;
        while (!originalStack.empty()) {
            tempStack.push(originalStack.top());
            originalStack.pop();
        }
        while (!tempStack.empty()) {
            originalStack.push(tempStack.top());
            cout << tempStack.top() << ", ";
            tempStack.pop();
        }
        cout << endl;
    }

    void print() {
        cout << "current plates: " << endl;
        for (int i = 0; i < sts.size(); i++)
            printStack(sts[i]);
        // while (!available.empty()) {
        //     cout << available.top() << ", ";
        //     available.pop();
        // }
        cout << endl;
    }
};

class DinnerPlates {
   private:
    vector<stack<int>> stacks;
    int capacity;
    set<int> not_full;   // 未满栈
    set<int> not_empty;  // 非空栈

   public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        not_full.insert(0);
        stacks.push_back(stack<int>());
    }

    void push(int val) {
        if (not_full.empty()) {
            stacks.emplace_back(stack<int>());
            not_full.insert(stacks.size() - 1);
        }
        int pos = *not_full.begin();
        stacks[pos].push(val);
        not_empty.insert(pos);
        if (stacks[pos].size() >= capacity)
            not_full.erase(pos);
    }

    int pop() {
        return (not_empty.size() > 0) ? (pop(*not_empty.rbegin())) : (-1);
    }

    int popAtStack(int index) {
        return (not_empty.count(index) > 0) ? (pop(index)) : (-1);
    }

    int pop(int index) {
        not_full.insert(index);
        int ret = stacks[index].top();
        stacks[index].pop();
        if (stacks[index].empty())
            not_empty.erase(index);
        return ret;
    }

    void print() {
        for (auto it = not_full.begin(); it != not_full.end(); it++)
            cout << *it << ", ";
        cout << endl;
        for (auto it = not_empty.begin(); it != not_empty.end(); it++)
            cout << *it << ", ";
        cout << endl;
    }
};

int test() {
    /*
    ["DinnerPlates","push","push","push","push","push","popAtStack","push",
    "push","popAtStack","popAtStack","pop","pop","pop","pop","pop"]
    [[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
    */
    auto p = DinnerPlates(2);
    for (int i = 1; i <= 5; i++)
        p.push(i);
    p.popAtStack(0);
    p.push(20);
    p.push(21);
    p.popAtStack(0);
    p.popAtStack(2);
    // for (int i = 0; i < 5; i++) {
    //     p.pop();
    //     p.print();
    // }
    return 0;
}

int main() {
    DinnerPlates plates(2);
    plates.push(1);
    plates.push(2);
    plates.push(3);
    plates.push(4);
    plates.push(5);
    plates.push(6);

    plates.print();  // 输出当前餐盘状态

    plates.popAtStack(1);  // 从第 1 个餐盘弹出一个元素
    plates.print();

    plates.popAtStack(1);  // 从第 1 个餐盘再弹出一个元素
    plates.print();

    plates.pop();  // 从最后一个餐盘弹出一个元素
    // plates.print();

    return 0;
}
