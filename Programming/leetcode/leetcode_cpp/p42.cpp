#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        int n = static_cast<int>(height.size());
        vector<int> left_high(n);
        // left_high[i] 表示height[0..i]的最大值
        vector<int> right_high(n);
        // right_high[i] 表示height[i..n-1]的最大值
        int max_height = height[0];
        for (int i = 0; i < n; i++) {
            max_height = max(max_height, height[i]);
            left_high[i] = max_height;
        }
        max_height = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            max_height = max(max_height, height[i]);
            right_high[i] = max_height;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += min(left_high[i], right_high[i]) - height[i];
        return ans;
    }
};
int main() {
    vector<int> nums{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << s.trap(nums) << endl;
}