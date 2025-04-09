
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> q;
        int ans = INT32_MIN;
        for (auto p : points) {
            int x = p[0], y = p[1];
            while (!q.empty() && q.front().first < x - k)
                q.pop_front();
            ans = max(ans, y + x + q.front().second);
            while (!q.empty() && q.back().second <= y - x)
                q.pop_back();
            q.push_back({x, y - x});
        }
        return ans;
    }
};