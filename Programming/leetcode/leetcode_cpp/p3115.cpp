#include <math.h>
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
    bool prime(int n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        for (int i = 2; i < sqrt(n) + 1; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int left = 0, right = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (prime(nums[i])) {
                left = i;
                break;
            }
        }
        for (size_t i = nums.size() - 1; i >= 0; i--) {
            if (prime(nums[i])) {
                right = i;
                break;
            }
        }
        return right - left;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vec{4, 2, 9, 5, 3};
    cout << s.maximumPrimeDifference(vec) << endl;
    return 0;
}