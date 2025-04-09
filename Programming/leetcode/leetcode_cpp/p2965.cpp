#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n * n + 1, 0);
        vector<int> ret;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]]++;
                if (pos[grid[i][j]] == 2)
                    ret.push_back(grid[i][j]);
            }

        for (int i = 1; i <= n * n; i++) {
            if (pos[i] == 0) {
                ret.push_back(i);
                return ret;
            }
        }
    }
};