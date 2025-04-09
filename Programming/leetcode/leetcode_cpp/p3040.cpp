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
    int most_op(vector<int>& nums, int t) { int n = nums.size(); }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int t1 = nums[0] + nums[1];
        int t2 = nums[n - 2] + nums[n - 1];
        int t3 = nums[0] + nums[n - 1];
    }
};