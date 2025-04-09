#include <algorithm>
#include <hash_map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool l_appear(vector<pair<int, int>> p, char c, int l) {
        int appear_time = 0;
        for (int i = 0; i < p.size(); i++) {
            int length = p[i].second - p[i].first + 1;
            if (length >= l)
                appear_time += length - l + 1;
            if (appear_time >= 3)
                return true;
        }
        return false;
    }
    int maximumLength(string s) {
        unordered_map<char, vector<pair<int, int>>> mp;
        int n = s.length();
        int begin = 0, end = -1;
        // 计算所在区间
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (i > 0 && c != s[i - 1]) {
                end = i - 1;
                // cout << s[i - 1] << " in: (" << begin << ", " << end << ")"
                //      << endl;

                if (mp.count(s[i - 1]) > 0)
                    mp[s[i - 1]].emplace_back(make_pair(begin, end));
                else
                    mp[s[i - 1]] =
                        vector<pair<int, int>>{make_pair(begin, end)};

                begin = i;
            }
        }

        end = n - 1;
        // cout << s[n - 1] << " in: (" << begin << ", " << end << ")" << endl;

        if (mp.count(s[n - 1]) > 0)
            mp[s[n - 1]].emplace_back(make_pair(begin, end));
        else
            mp[s[n - 1]] = vector<pair<int, int>>{make_pair(begin, end)};
        int ret = -1;
        for (auto p : mp) {
            int l = 1;
            char c = p.first;
            while (l_appear(p.second, c, l)) {
                ret = max(ret, l);
                l += 1;
            }
            /*
            // cout << p.first << ", at: " << endl;
            priority_queue<int, vector<int>, greater<int>> que;
            for (auto r : p.second) {
                // 对于连续出现的
                // cout << "(" << r.first << ", " << r.second << ");  ";
                int begin = r.first;
                int end = r.second;
                int length = end - begin + 1;
                if (length >= 3) {
                    ret = max(ret, length - 2);
                }
                // 不连续出现的, 要找top 3
                que.emplace(length);
                if (que.size() > 3)
                    que.pop();
            }
            if (que.size() == 3) {
                ret = max(ret, que.top());
            }
            // cout << endl;
            */
        }
        return ret;
    }
};
int main() {
    Solution s = Solution();
    cout << s.maximumLength("sssddssxdassdd") << endl;
}