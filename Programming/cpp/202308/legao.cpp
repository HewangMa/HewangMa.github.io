#include <bits/stdc++.h>
using namespace std;
void p1001()
{
    int l = 0;
    cin >> l;
    int ret = 0;
    for (int a = 1; a <= l / 2; a++)
    {
        for (int b = a; b <= l / 2; b++)
        {
            int c = l - a - b;
            if (!(a == b && b == c) && (a + b > c && a + c > b) && (c >= b))
                ret++;
        }
    }
    cout << ret << endl;
}
void p1003()
{
    string s, a;
    getline(cin, s);
    getline(cin, a);
    int pos = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            pos++;
        else
        {
            bool tag = true;
            for (int j = 0; j < a.size(); j++)
            {
                if (s[i + j] != a[j])
                {
                    tag = false;
                    break;
                }
            }
            if (tag == true)
            {
                break;
            }
        }
    }
    cout << pos << endl;
}
void p1253()
{
    int n;
    cin >> n;
    int dp[55];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    // 1 1 2 3 5 8
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
}
void cd202009_1_5()
{
    int n;
    cin >> n;
    int tot = 0;
    int k = 0;
    for (; k * (k + 1) / 2 <= n; k++)
    {
        tot += k;
    }
    tot += (n - k) * k;
    cout << tot << endl;
}
void cd202009_3_3()
{
    string s;
    while (getline(cin, s))
    {
        int ans[110] = {0};
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    ans[i] = 2;
            }
        }
        while (!st.empty())
        {
            ans[st.top()] = 1;
            st.pop();
        }
        for (int i = 0; i < s.size(); i++)
        {
            // cout << i << endl;
            if (ans[i] == 1)
                cout << '$';
            else if (ans[i] == 2)
                cout << '?';
            else
                cout << s[i];
        }
        cout << endl;
    }
}
void p1921()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    int age = a[x][y];
    // cout << "age:" << age << endl;
    int cnt = 0;
    for (int j = 0; j < m; j++)
        if (a[x][j] == age)
            cnt++;
    for (int i = 0; i < n; i++)
        if (a[i][y] == age)
            cnt++;
    cout << cnt - 2 << endl;
}
int main()
{
    p1921();
    return 0;
}