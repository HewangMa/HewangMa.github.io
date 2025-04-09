#include <algorithm>
#include <hash_map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class cmp {
   public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second - a.first + 1 > b.second - b.first + 1;
    }
};

#define QUE priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>

class Solution {
   public:
    void push_mp(unordered_map<char, QUE>& mp, char c, pair<int, int> p) {
        if (mp.count(c) > 0) {
            mp[c].push(p);
            if (mp[c].size() > 3)
                mp[c].pop();
        } else {
            mp[c] = QUE();
            mp[c].push(p);
        }
    }
    // 这部分可以优化
    bool l_appear(QUE p, int l) {
        int appear_time = 0;
        while (!p.empty()) {
            pair<int, int> pi = p.top();
            p.pop();
            int length = pi.second - pi.first + 1;
            if (length >= l)
                appear_time += length - l + 1;
            if (appear_time >= 3)
                return true;
        }
        return false;
    }
    int maximumLength(string s) {
        unordered_map<char, QUE> mp;
        int n = s.length();
        int begin = 0, end = -1;
        // 计算所在区间
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (i > 0 && c != s[i - 1]) {
                end = i - 1;
                push_mp(mp, s[i - 1], make_pair(begin, end));
                begin = i;
            }
        }

        end = n - 1;
        push_mp(mp, s[n - 1], make_pair(begin, end));
        int ret = -1;

        for (auto p : mp) {
            int l = 1;
            char c = p.first;
            while (l_appear(p.second, l)) {
                ret = max(ret, l);
                l += 1;
            }
        }
        return ret;
    }
};