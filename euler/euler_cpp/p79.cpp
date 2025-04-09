#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int first_pos()
{
}
void solve1()
{
    int num[] = {
        319,
        680,
        180,
        690,
        129,
        620,
        762,
        689,
        762,
        318,
        368,
        710,
        720,
        710,
        629,
        168,
        160,
        689,
        716,
        731,
        736,
        729,
        316,
        729,
        729,
        710,
        769,
        290,
        719,
        680,
        318,
        389,
        162,
        289,
        162,
        718,
        729,
        319,
        790,
        680,
        890,
        362,
        319,
        760,
        316,
        729,
        380,
        319,
        728,
        716,
    };
    string num_str[55];
    for (int i = 0; i < 50; i++)
        num_str[i] = to_string(num[i]);
    string ans = "";
    for (int i = 0; i < 50; i++)
    {
        int a = ans.find_first_of(num_str[i][0], 0);
        if (a == -1)
        {
            ans += num_str[i][0];
            continue;
        }
        else
    }
}

int main()
{
    test();
}