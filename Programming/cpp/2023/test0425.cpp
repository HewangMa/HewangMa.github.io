#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class DinnerPlates
{
public:
    int counts;
    int left;
    int right;
    int capacity;
    vector<int> tops;
    vector<vector<int>> sts;
    DinnerPlates(int capacity)
    {
        this->capacity = capacity;
        counts = (int)min(200000.0 / capacity + 1, 100001.0);
        // cout<<counts<<endl;
        left = 0;
        right = counts - 1;
        tops = vector<int>(counts, 0);
        sts = vector<vector<int>>(counts, vector<int>(capacity));
        // cout<<"one##"<<endl;
    }
    void push(int val)
    {
        int i = min(left, right);
        // cout<<capacity<<endl;
        while (i < counts && tops[i] == capacity)
            i++;
        if (i == counts)
        {
            cout << "full" << endl;
            return;
        }
        left = i;
        sts[i][tops[i]++] = val;
    }
    int pop()
    {
        int i = max(left, right);
        // int i=counts-1;
        while (i >= 0 && tops[i] == 0)
            i--;
        if (i == -1)
            return -1;
        right = i;
        tops[i]--;
        return sts[i][tops[i]];
    }
    int popAtStack(int index)
    {
        if (index < 0 || index >= counts)
            return -1;
        if (tops[index] == 0)
            return -1;
        left = min(left, index);
        tops[index]--;
        return sts[index][tops[index]];
    }
};
void test01()
{
    DinnerPlates *dp = new DinnerPlates(1);
    for (int i = 0; i < 34; i++)
        dp->push(i);
    for (int i = 3; i < 9; i++)
        cout << dp->popAtStack(i) << " ";
    cout << endl;
    for (int i = 4; i < 23; i++)
        cout << dp->popAtStack(i) << " ";
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
