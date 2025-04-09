#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(nums[i]);
        if (s.size() >= 3) {
            s.erase(*s.rbegin());
            s.erase(*s.rbegin());
        }
        return *s.rbegin();
    }
};