#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> presum(n, 0);
        presum[0] = nums[0];
        for (int i = 1; i < n; i++)
            presum[i] = presum[i - 1] + nums[i];
        vector<long long> op_count;
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            long long count = 0;
            long long line = queries[i];
            vector<int>::iterator it =
                lower_bound(nums.begin(), nums.end(), line);
            if (it != nums.end()) {
                int pos = it - nums.begin();
                long long front = (pos == 0) ? (0) : (presum[pos - 1]);
                count += line * pos - front;
                count += presum[n - 1] - front - line * (n - pos);
            } else
                count += abs(presum[n - 1] - line * n);
            op_count.emplace_back(count);
        }
        return op_count;
    }
};

int main() {
    vector<int> nums{1, 3, 6, 8};  // n - pos
    int target = 5;
    int pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    cout << nums[pos] << endl;
}