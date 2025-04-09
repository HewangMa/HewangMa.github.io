
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution1 {
   public:
    class Scompare0 {
       public:
        // bool operator()(const vector<int>& c1, const vector<int>& c2) {
        //     return op(c1[0], c1[1]) > op(c2[0], c2[1]);
        // }
    };
    class Scompare1 {
       public:
        bool operator()(const vector<int>& c1, const vector<int>& c2) {
            double l = ceil(1.0 * c1[1] / c1[0]);
            double r = ceil(1.0 * c2[1] / c2[0]);
            return l < r;
        }
    };
    int ans = 0;
    int op(int b, int v) { return ceil(1.0 * v / b); }
    int op(vector<int> p) { return op(p[0], p[1]); }
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        for (int i = 0; i < bucket.size(); i++) {
            if (vat[i] == 0)
                continue;
            if (bucket[i] == 0) {
                bucket[i]++;
                ans++;
            }
        }
        // 使用优先队列找到比例最大的那个，判断是否要升级
        priority_queue<vector<int>, vector<vector<int>>, Scompare1> Q;

        for (int i = 0; i < bucket.size(); i++)
            if (vat[i] != 0)
                Q.push(vector<int>{bucket[i], vat[i]});
        if (Q.size() == 0)
            return 0;

        int b = Q.top()[0];
        int v = Q.top()[1];
        while (true) {
            int add = 1 + op(b + 1, v);
            int not_add = op(b, v);
            if (add >= not_add)
                break;
            ans = add;
            // while (op(Q.top()) ==)
            //     Q.pop();
            Q.push(vector<int>{b + 1, v});
            b = Q.top()[0];
            v = Q.top()[1];
        }
        ans += ceil(1.0 * v / b);
        return ans;
    }
};

class Solution {
   public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        int max_vat = *max_element(vat.begin(), vat.end());
        if (max_vat == 0)
            return 0;
        int op = INT32_MAX;
        for (int k = 1; k <= max_vat && k < op; k++) {
            int t = k;
            for (int i = 0; i < n; i++) {
                double v = vat[i];
                int b = bucket[i];
                t += max(0, int(ceil(v / k) - b));
            }
            op = min(op, t);
        }
        return op;
    }
};
