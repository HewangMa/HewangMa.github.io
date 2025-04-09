#include <algorithm>
#include <hash_map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i + 1 < n; i += 2) {
            ret.push_back(nums[i + 1]);
            ret.push_back(nums[i]);
        }
        return ret;
    }
};