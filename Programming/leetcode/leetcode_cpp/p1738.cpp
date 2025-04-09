#include <math.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pre_sum(m, vector<int>(n, 0));
        vector<int> xs;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = (i == 0) ? (0) : (pre_sum[i - 1][j]);
                int left = (j == 0) ? (0) : (pre_sum[i][j - 1]);
                int up_left =
                    (j == 0 || i == 0) ? (0) : (pre_sum[i - 1][j - 1]);
                pre_sum[i][j] = up ^ left ^ up_left ^ matrix[i][j];
                xs.emplace_back(pre_sum[i][j]);
            }  // 计算完每一行的前缀和
        }
        sort(xs.begin(), xs.end(), greater<int>());
        return xs[k - 1];
    }
};
int main() {
    Solution s = Solution();
    // vector<vector<int>> matrix = {{5, 2}, {1, 6}};
    vector<vector<int>> matrix = {{10, 9, 5}, {2, 0, 4}, {1, 0, 9}, {3, 4, 8}};

    // vector<vector<int>> matrix = {
    //     {8, 10, 5, 8, 5, 7, 6, 0, 1, 4, 10, 6, 4, 3, 6, 8, 7, 9, 4, 2}};
    cout << "The ans: " << s.kthLargestValue(matrix, 2) << endl;
    return 0;
}