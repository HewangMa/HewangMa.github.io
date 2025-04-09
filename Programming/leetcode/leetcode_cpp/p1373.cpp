#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   private:
    int ans = 0;

   public:
    vector<int> maxSumBST_(TreeNode* root) {
        if (!root)
            return vector<int>{0, INT32_MIN, INT32_MAX, true};
        // { root中所有键值和，root中的最大值，root中的最小值,是不是二分查找树}
        if (!root->left && !root->right) {
            ans = max(ans, root->val);
            return vector<int>{root->val, root->val, root->val, true};
        }
        vector<int> left_info = maxSumBST_(root->left);
        vector<int> right_info = maxSumBST_(root->right);

        bool tag = root->val > left_info[1] && root->val < right_info[2] &&
                   left_info[3] && right_info[3];

        int tree_max = max(max(left_info[1], right_info[1]), root->val);
        int tree_min = min(min(left_info[2], right_info[2]), root->val);
        int total_sum = root->val + left_info[0] + right_info[0];
        if (tag)
            ans = max(ans, total_sum);
        return vector<int>{total_sum, tree_max, tree_min, tag};
    }

    int maxSumBST(TreeNode* root) {
        vector<int> p = maxSumBST_(root);
        return ans;
    }
};
