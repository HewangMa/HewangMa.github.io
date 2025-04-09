
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int remain_sum = mean * (m + n);
        for (auto r : rolls)
            remain_sum -= r;

        int base = remain_sum / n;
        int edge = remain_sum - base * n;

        if (base > 6 || base == 6 && edge > 0 || base <= 0)
            return vector<int>();
        vector<int> ret(n, base);
        for (int i = 0; i < edge; i++)
            ret[i] += 1;

        return ret;
    }
};