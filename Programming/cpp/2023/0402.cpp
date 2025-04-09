#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <unordered_map>
using namespace std;
void absSort(float *nums, int n)
{

    function<int(int, int)> add = [](int a, int b)
    { return a + b; };

    sort(nums, nums + n, [](float a, float b)
         { return abs(a) < abs(b); });

    for (int i = 0; i < n; i++)
    {
        cout << add(nums[i], 3) << endl;
    }
}

void test01()
{
    float a[12] = {1.0, 8.0, -3.0, -2.0, 5.0, -1.0};
    absSort(a, 6);
    for (int i = 0; i < 6; i++)
        cout << a[i] << ' ';
}

int test02()
{
    int x = 8, y = 9;

    auto add = [](int a, int b)
    { return a + b; };
    std::function<int(int, int)> Add = [=](int a, int b)
    { return add(a, b); };

    cout << "add: " << add(x, y) << endl;
    cout << "Add: " << Add(x, y) << endl;

    return 0;
}

class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        unordered_map<int, int> memo;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j) -> int
        {
            if (i + 2 > j)
            {
                return 0;
            }
            if (i + 2 == j)
            {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j; // ���仯���� ��һά�����ʾ��ά���� һά�������������ӳ��
            if (!memo.count(key))
            {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    minScore = min(minScore, values[i] * values[k] * values[j] + dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};

int main()
{

    Solution t;
    vector<int> a = {1, 4, 6, 5, 1, 3};
    cout << t.minScoreTriangulation(a) << endl;

    // cout<<test02()<<endl;
    return 0;
}
