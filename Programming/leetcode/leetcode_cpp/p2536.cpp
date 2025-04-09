#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
        int q_size = queries.size();
        for (int i = 0; i < q_size; i++) {
            vector<int> q = queries[i];
            mat[q[0]][q[1]]++;
            mat[q[2] + 1][q[3] + 1]++;
            mat[q[0]][q[3] + 1]--;
            mat[q[2] + 1][q[1]]--;
        }
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] += mat[i - 1][j];
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                mat[i][j] += mat[i][j - 1];
        mat.resize(n);
        for (vector<int>& row : mat)
            row.resize(n);
        return mat;
    }
};