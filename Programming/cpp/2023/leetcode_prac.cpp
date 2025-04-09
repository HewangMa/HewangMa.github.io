#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {
        // cout<<s.find('c')<<endl;
        int n = s.size();
        // return 0;
        int mp[28];
        for (int i = 0; i < 26; i++)
        {
            if (s.find('a' + i) != string::npos)
            {
                int pos = chars.find(i + 'a');
                if (pos >= 0)
                    mp[i] = vals[pos];
                else
                    mp[i] = i + 1;
            }
            else
                mp[i] = 0;
        }
        // cout<<"mp:";
        // for (int i=0;i<26;i++)cout<<mp[i]<<' ';
        // cout<<endl;

        int dp[n]; // dp[i]表示以s[i]为结尾的子串的最大开销
        dp[0] = mp[s[0] - 'a'];
        int ans = max(0, dp[0]);

        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + mp[s[i] - 'a'], mp[s[i] - 'a']);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
void test01()
{
    Solution s;
    vector<int> vals = {-1, -1, -1};
    cout << s.maximumCostSubstring("abc", "abc", vals) << endl;
}
int main()
{
    test01();
    return 0;
}