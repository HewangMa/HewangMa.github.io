#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution1 {
   public:
    int maxCoins(vector<int>& nums) {
        // 假如有0 就先戳0
        vector<int> re_nums;
        for (int num : nums)
            if (num != 0)
                re_nums.emplace_back(num);
        int n = re_nums.size();
        // 如果戳完0之后少于2个
        if (n == 1)
            return re_nums[0];
        if (n == 0)
            return 0;
        // 保存前后邻居的位置
        // 为什么不用双向链表呢？因为不好索引
        vector<vector<int>> neighbor(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            neighbor[i][0] = i - 1;
            neighbor[i][1] = i + 1;
        }

        // 存数字的位置下标
        vector<vector<int>> poss(101, vector<int>());
        for (int i = 0; i < n; i++) {
            poss[re_nums[i]].emplace_back(i);
        }

        int ret = 0;
        // 在renums[1:n-1]之间选择最小的 戳，这让人想到
        // 斐波那契堆，但是应该没必要
        for (int stick = 1; stick <= 100; stick++) {
            vector<int> pos = poss[stick];
            if (pos.size() == 0)
                continue;
            // cout << "s: " << stick << " ";
            // for (auto pr : pos)
            //     cout << pr << ", ";
            // cout << endl;

            for (unsigned i = 0; i < pos.size(); i++) {
                int p = pos[i];
                if (p == 0 || p == n - 1)
                    continue;
                // 开始戳
                int left = re_nums[neighbor[p][0]];
                int right = re_nums[neighbor[p][1]];
                // 把左边的右邻居赋值成自己的右邻居
                neighbor[neighbor[p][0]][1] = neighbor[p][1];
                // 把右边的左邻居赋值成自己的左邻居
                neighbor[neighbor[p][1]][0] = neighbor[p][0];
                ret += re_nums[p] * left * right;
                cout << "sticked " << stick << " at " << p << " whose left is "
                     << left << " and right is " << right << endl;
            }
        }
        // 左右两边的最后戳
        int two = re_nums[0] > re_nums[n - 1] ? re_nums[0] : re_nums[n - 1];
        int one = re_nums[0] + re_nums[n - 1] - two;
        ret += (one * two + two);
        return ret;
    }
};

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        // 假如有0 就先戳0
        vector<int> re_nums;
        for (int num : nums)
            if (num != 0)
                re_nums.emplace_back(num);
        int n = re_nums.size();
        // 如果戳完0之后少于2个
        if (n == 1)
            return re_nums[0];
        if (n == 0)
            return 0;
        // 保存前后邻居的位置
        // 为什么不用双向链表呢？因为不好索引
        vector<vector<int>> neighbor(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            neighbor[i][0] = i - 1;
            neighbor[i][1] = i + 1;
        }

        // 存数字的位置下标
        vector<vector<int>> poss(101, vector<int>());
        for (int i = 0; i < n; i++) {
            poss[re_nums[i]].emplace_back(i);
        }

        int ret = 0;
        // 在renums中选择最小的 戳，这让人想到
        // 斐波那契堆，但是应该没必要
        for (int stick = 1; stick <= 100; stick++) {
            if (poss[stick].size() == 0)
                continue;

            for (unsigned i = 0; i < poss[stick].size(); i++) {
                cout << "here? " << endl;
                int p = poss[stick][i];

                // 开始戳
                int left = 1;
                if (neighbor[p][0] != -1) {
                    left = re_nums[neighbor[p][0]];
                    // 把左边的右邻居赋值成自己的右邻居
                    neighbor[neighbor[p][0]][1] = neighbor[p][1];
                }
                int right = 1;
                if (neighbor[p][1] != n) {
                    right = re_nums[neighbor[p][1]];
                    // 把右边的左邻居赋值成自己的左邻居
                    neighbor[neighbor[p][1]][0] = neighbor[p][0];
                }
                ret += re_nums[p] * left * right;
                cout << "sticked " << stick << " at " << p << " whose left is "
                     << left << " and right is " << right << endl;
            }
        }
        return ret;
    }
};

int main() {
    cout << 
    21 * 64 * 97 
    + 76 * 64 * 97 
    + 76 * 9 * 97 
    + 9 * 97 
    + 60 * 97 
    + 97
         << endl;
    // Solution s = Solution();
    // vector<int> balloon{9, 76, 64, 21, 97, 60};
    // cout << s.maxCoins(balloon);
    return 0;
}