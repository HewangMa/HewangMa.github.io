#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool cross(vector<int>& a, vector<int>& b) {
        return a[1] >= b[0] && a[0] <= b[1];
    }
    int countWays1(vector<vector<int>>& ranges) {
        int range_size = static_cast<int>(ranges.size());
        vector<int> belongs(ranges.size() + 1);
        for (int i = 0; i < range_size; i++)
            belongs[i] = i;

        for (int i = 0; i < range_size; i++)
            for (int j = 0; j < i; j++)
                if (cross(ranges[i], ranges[j])) {
                    if (belongs[i] != i)
                        belongs[j] = belongs[i];
                    else
                        belongs[i] = belongs[j];
                }

        set<int> st;
        for (int i = 0; i < range_size; i++)
            st.insert(belongs[i]);

        int gs = st.size();
        cout << "gs: " << gs << endl;
        int dp[gs + 5][gs + 5];
        dp[0][0] = 1;  // dp是杨辉三角,用来计算组合数 进而计算卡特兰数字
        for (int i = 0; i <= gs; i++) {
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        for (int i = 2; i <= gs + 1; i++)
            for (int j = 1; j < i; j++)
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;

        int ans = 0;
        for (int j = 0; j <= gs; j++)
            ans = (ans + dp[gs][j]) % 1000000007;
        return ans;
    }

    int countWays2(vector<vector<int>>& ranges) {
        int range_size = static_cast<int>(ranges.size());
        vector<int> belongs(ranges.size() + 1);
        for (int i = 0; i < range_size; i++)
            belongs[i] = i;

        for (int i = 0; i < range_size; i++)
            for (int j = 0; j < i; j++)
                if (cross(ranges[i], ranges[j])) {
                    if (belongs[i] != i)
                        belongs[j] = belongs[i];
                    else
                        belongs[i] = belongs[j];
                }

        set<int> st;
        for (int i = 0; i < range_size; i++)
            st.insert(belongs[i]);
        int k = st.size();
        int ans = 1;
        int mod = 1000000007;
        for (int i = 0; i < k; i++)
            ans = (ans * 2) % mod;
        return ans;
    }

    static bool cmp(const vector<int>& r1, const vector<int>& r2) {
        return r1[0] < r2[0];
    }
    
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), cmp);
        int mod = 1e9 + 7;
        int n = ranges.size();
        int ans = 1;
        for (int i = 0; i < n;) {
            int r = ranges[i][1];
            int j = i + 1;
            while (j < n && ranges[j][0] <= r) {
                r = max(r, ranges[j][1]);
                j++;
            }
            ans = (ans * 2) % mod;
            i = j;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> ranges{{34, 56}, {28, 29}, {12, 16}, {11, 48},
                               {28, 54}, {22, 55}, {28, 41}, {41, 44}};
    Solution s;
    s.countWays(ranges);
    return 0;
}