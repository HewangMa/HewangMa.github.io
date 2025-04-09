#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    // 小顶堆
    // 时间复杂度：O(nlogk)
    // 空间复杂度：O(n)
    // https://leetcode.cn/problems/top-k-frequent-elements/
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &lhss, const pair<int, int> &rhs)
        {
            return lhss.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 要统计元素出现频率
        unordered_map<int, int> mapp; // mapp<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++)
        {
            mapp[nums[i]]++;
        }
        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = mapp.begin(); it != mapp.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }

    // https://leetcode.cn/problems/dota2-senate/
    string predictPartyVictory1(string senate)
    {
        char first = senate[0];
        string ans = "";
        while (senate.size() > 0)
        {
            int j = 0;
            for (; j < senate.size(); j++)
            {
                if (senate[j] != senate[0])
                {
                    senate.erase(j, 1);
                    senate.erase(0, 1);
                    cout << senate << endl;
                    break;
                }
            }
            if (j == senate.size())
            {
                if (senate[0] == 'R')
                    return "Radiant";
                else
                    return "Dire";
            }
        }
        if (senate.size() == 0)
        {
            if (first == 'R')
                return "Radiant";
            else
                return "Dire";
        }
        return ans;
    }
    string predictPartyVictory2(string senate)
    {
        int Rnums = 0;
        int Dnums = 0;
        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
                Rnums++;
            else
                Dnums++;
        }
        return " ";
    }
    string predictPartyVictory(string senate)
    {
        while (!finished(senate))
        {
            for (int i = 0; i < senate.size(); i++)
            {
                // i是决策者，每次选择杀掉自己后面的对手
                int j = i + 1;
                cout << i << endl;
                for (; j < senate.size(); j++)
                {
                    if (senate[j] != senate[i])
                    {
                        // 遇到了对手杀掉他
                        senate.erase(j, 1);
                        cout << senate << endl;
                        break;
                    }
                }
                if (j == senate.size())
                { // 后面已经没对手了 往前找
                    for (j = 0; j < i; j++)
                    {
                        if (senate[j] != senate[i])
                        {
                            // 遇到了对手杀掉他
                            senate.erase(j, 1);
                            break;
                        }
                    }
                    if (j == i)
                    {
                        // 前面也没对手了 直接结束游戏
                        return (senate[i] == 'R') ? ("Radiant") : ("Dire");
                    }
                }
            }
        }
        // while结束了 返回剩下的结果
        return (senate[0] == 'R') ? ("Radiant") : ("Dire");
    }

    string longestPalindrome(string s)
    {
        bool dp[1010][1010]; // dp[i][j]表示s[i..j]是不是回文子串
        // dp[i][j]=(s[i]==s[j])&&(dp[i+1][j-1]);
        // for (int i=0;i<s.size();i++)dp[i][i]=true;
        for (unsigned int i = 0; i < s.size(); i++)
        {
            for (unsigned int j = 0; j <= i; j++)
                dp[i][j] = true;
        }

        for (unsigned int i = 0; i < s.size(); i++)
        {
            for (unsigned int j = i + 1; j < s.size(); j++)
            {
                dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
                cout << "(" << i << "," << j << ") " << dp[i][j] << endl;
            }
        }
        unsigned int maxLength = 1;
        int iindex = 0, jindex = 0;
        for (unsigned int i = 0; i < s.size(); i++)
        {
            for (unsigned int j = i + 1; j < s.size(); j++)
            {
                if (dp[i][j] && (j - i + 1 > maxLength))
                {
                    maxLength = j - i + 1;
                    cout << "!~";
                    iindex = i;
                    jindex = j;
                }
            }
        }
        return s.substr(iindex, jindex - iindex + 1);
    }

    // https://leetcode.cn/problems/numbers-with-repeated-digits/
    bool dupD(int n)
    {
        set<int> st;
        while (n)
        {
            int a = n % 10;
            n /= 10;
            if (st.sount[a] == 0)
                st.insert(a);
            else
                return true;
        }
        return false;
    }
    int numDupDigitsAtMostN(int n)
    {
        int dp[12];
        // dp[i]��ʾ[1,10^i]���������ظ����ֵĸ���
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 10;
        dp[3] = 262; // 1000
        int ans = 0;
        for (int i = 1001; i <= 10000; i++)
        {
            if (dupD(i))
                ans++;
        }
        return ans + dp[3];
        /*
        int wei=0;
        while(n){
            n/=10;
            wei++;
        }
        int ans=0;
        for (int i=pow(10,wei-1)+1;i<=n;i++){
            if(dupD(i))ans++;
        }
        ans+=dp[wei-1];
        */
    }
};
void test01()
{
    Solution solu;
    vector<int> nums = {1, 5, 9, 3, 54, 2, 5, 4, 2, 45, 21, 4, 5, 2, 5, 5};
    string senate = "aaaa";
    // vector<int> ans = solu.topKFrequent(nums, 3);
    // copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << solu.longestPalindrome(senate) << endl;
    /*
    string s = "aaaa";
    cout << longestPalindrome2(s) << endl;
    cout << "hello" << endl;
    return 0;
    */
}
string longestPalindrome2(string s)
{
    bool dp[1010][1010]; // dp[i][j]表示s[i..j]是不是回文子串
    // dp[i][j]=(s[i]==s[j])&&(dp[i+1][j-1]);
    // for (int i=0;i<s.size();i++)dp[i][i]=true;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        for (unsigned int j = 0; j <= i; j++)
            dp[i][j] = true;
    }
    int j = 1;
    while (j < s.size())
    {
        for (int step = 0; j + step < s.size(); step++)
        {
            dp[step][j + step] = (s[step] == s[j + step]) && (dp[step + 1][j + step - 1]);
            cout << "(" << step << "," << j + step << ") " << dp[step][j + step] << endl;
        }
        j++;
    }
    /*
    for (unsigned int i=0;i<s.size();i++){
        for (unsigned int j=i+1;j<s.size();j++){
            dp[i][j]=(s[i]==s[j])&&(dp[i+1][j-1]);
            cout<<"("<<i<<","<<j<<") "<<dp[i][j]<<endl;
        }
    }
    */
    unsigned int maxLength = 1;
    int iindex = 0, jindex = 0;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        for (unsigned int j = i + 1; j < s.size(); j++)
        {
            if (dp[i][j] && (j - i + 1 > maxLength))
            {
                maxLength = j - i + 1;
                cout << "!~";
                iindex = i;
                jindex = j;
            }
        }
    }
    return s.substr(iindex, jindex - iindex + 1);
}
void test02()
{
    cout << numDupDigitsAtMostN(4) << endl;
}
void absSort(float *nums, int n)
{
    sort(nums, nums + n, [](float a, float b)
         { return abs(a), abs(b) });
}
int main()
{
    float a[12] = {1.0, 8.0, -3.0, -2.0, 5.0, -1.0};
    absSort(a, 6);
    for (int i = 0; i < 6; i++)
        cout << a << ' ';
}
