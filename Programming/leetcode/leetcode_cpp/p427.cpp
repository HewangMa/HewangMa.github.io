#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val,
         bool _isLeaf,
         Node* _topLeft,
         Node* _topRight,
         Node* _bottomLeft,
         Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
   private:
    int m;
    int n;
    int sum[65][65];

   public:
    void cal_sum(vector<vector<int>>& grid) {
        cout << "for grid: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << grid[i][j] << ", ";
            cout << endl;
        }
        sum[0][0] = grid[0][0];
        for (int j = 1; j < n; j++)
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        int row[65];
        for (int i = 1; i < m; i++) {
            row[0] = grid[i][0];
            sum[i][0] = row[0] + sum[i - 1][0];
            for (int j = 1; j < n; j++) {
                row[j] = row[j - 1] + grid[i][j];
                sum[i][j] = sum[i - 1][j] + row[j];
            }
        }
        cout << "got sum:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << sum[i][j] << ", ";
            cout << endl;
        }
    }

    int area_sum(int si, int ei, int sj, int ej) {
        int ret = sum[ei][ej];
        if (si > 0)
            ret -= sum[si - 1][ej];
        if (sj > 0)
            ret -= sum[ei][sj - 1];
        if (si > 0 && sj > 0)
            ret += sum[si - 1][sj - 1];
        return ret;
    }

    Node* construct_(vector<vector<int>>& grid,
                     int si,
                     int ei,
                     int sj,
                     int ej) {
        if (si > ei || sj > ej)
            return nullptr;
        if (si == ei && sj == ej)
            return new Node(grid[si][sj], true);
        int _area_sum = area_sum(si, ei, sj, ej);
        if (_area_sum == 0)
            return new Node(0, true);
        if (_area_sum == (ei - si + 1) * (ej - sj + 1))
            return new Node(1, true);
        int mi = (ei + si) >> 1;
        int mj = (ej + sj) >> 1;
        // cout << "heihei: " << mi << ", " << mj << endl;
        Node* top_left = construct_(grid, si, mi, sj, mj);
        Node* top_right = construct_(grid, si, mi, mj + 1, ej);
        Node* down_left = construct_(grid, mi + 1, ei, sj, mj);
        Node* down_right = construct_(grid, mi + 1, ei, mj + 1, ej);
        // cout << "hh: " << si << ", " << ei << ", " << sj << ", " << ej <<
        // endl;
        return new Node(1, false, top_left, top_right, down_left, down_right);
    }

    Node* construct(vector<vector<int>>& grid) {
        m = static_cast<int>(grid.size());
        n = static_cast<int>(grid[0].size());
        cal_sum(grid);
        return construct_(grid, 0, m - 1, 0, n - 1);
    }
};

int main() {
    vector<vector<int>> grid{{2, 1, 1}, {1, 3, 4}, {3, 2, 1}, {1, 5, 1}};
    Solution s;
    s.construct(grid);
    return 0;
}