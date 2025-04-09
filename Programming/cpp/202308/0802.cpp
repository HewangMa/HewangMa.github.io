#include <bits/stdc++.h>
#include<string>
using namespace std;
void test02()
{
    int m, n;
    int nums[100][100];
    cin>>m>>n;
    for (int i = 0;i<m;i++)
        for (int j = 0; j < n;j++)
            cin >> nums[i][j];
    for (int i = 0; i < m;i++){
        for (int j = 0;j<n;j++)
            cout << nums[i][j] << ' ';
        cout << endl;
    }
}
void test01()
{
    int n,a[100];
    cin>>n;
    int s = 0;
    srand((int)time(0));
    for (int i = 0; i < n;i++){
        a[i] = rand() % 20;
        if(a[i]>s)
            s = a[i];
    }
    cout << s << endl;
}
void test03()
{
    string s;

    getline(cin, s);
    cout << s << endl;

    for (int i = 0; i < s.size();i++)
    {
        s[i] = s[i] - 'a' + 'A';
    }
    cout << s << endl;

    //http://124.220.203.211/home


}
void test04()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    int num = 0, low = 0, up = 0, space = 0;
    for (int i = 0; i < s.size();i++)
    {
        if (s[i]>='0' && s[i]<'9')
            num++;
        else if(s[i]>='a' && s[i]<='z')
            low++;
        else if(s[i]>='A' && s[i]<='Z')
            up++;
        else if (s[i]==' ')
            space++;
        else
            cout << s[i] << ' ';
    }
    cout << endl
         << endl
         << "$$$" << endl
         << endl;
    cout << space << endl;
    cout << num << endl;
    cout << up << endl;
    cout << low << endl;
}
void test05()
{
    string s1 = "eaorg";
    string s2 = "ega";
    cout << (s1 < s2) << endl;//比较 strcmp
    cout << s1 + s2 << endl;//拼接 strcat
    cout << s1.substr(1, 2) << endl; // 子字符串
}
void reverse(string &s,int left,int right){
    //把s的left到right 反转
    
}
void test06(){
    string s;
    getline(cin,s);
    for (int i = 0; i < s.size();i++)
    {
        //调用reverse
    }
    cout << s << endl;
}
int main()
{
    test05();
    return 0;
}