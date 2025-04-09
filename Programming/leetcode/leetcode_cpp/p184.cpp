#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

class Checkout {
   private:
    deque<int> dq;
    queue<int> q;

   public:
    Checkout() {}

    int get_max() { return (dq.size() > 0) ? (dq.front()) : (-1); }

    void add(int value) {
        while (!dq.empty() && dq.back() < value)
            dq.pop_back();
        dq.push_back(value);
        q.push(value);
    }

    int remove() {
        if (q.size() <= 0)
            return -1;
        int r = q.front();
        q.pop();
        if (r == dq.front())
            dq.pop_front();
        return r;
    }
};
