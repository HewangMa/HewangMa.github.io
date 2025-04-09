#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    // right算法判断 以a1为基点， a2 的旋转角度是否比 a3大（简称 a3在a2的右边）
    // 方法是极坐标计算角度//但该方法似乎不太好用
    bool right1(vector<int>& a1,
                vector<int> a2,
                vector<int> a3) {  // a2 和a3 使用值传递

        double si3, si2, r3, r2;
        // 移动到原点
        a2[0] -= a1[0];
        a2[1] -= a1[1];
        a3[0] -= a1[0];
        a3[1] -= a1[1];
        r3 = sqrt(a3[1] * a3[1] + a3[0] * a3[0]);
        r2 = sqrt(a2[1] * a2[1] + a2[0] * a2[0]);

        cout << "r3: " << r3 << "  r2: " << r2 << endl;

        si3 = acos(a3[0] * 1.0 / r3);
        // if(a3[1]<0) si3=2*3.1415926-si3;
        si2 = acos(a2[0] * 1.0 / r2);
        //  if(a2[1]<0) si2=2*3.1415926-si2;
        cout << "si3: " << si3 << "  si2:" << si2 << endl;

        return si2 >= si3;
    }

    // right算法判断 以a1为基点， a2 的旋转角度是否比 a3大（简称 a3在a2的右边）
    int right(vector<int> a1, vector<int> a2, vector<int> a3) {
        return (a2[0] - a1[0]) * (a3[1] - a2[1]) -
               (a2[1] - a1[1]) * (a3[0] - a2[0]);
    }  // 使用向量叉积

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;
        int n = trees.size();
        vector<bool> pushed;
        for (int i = 0; i < n; i++)
            pushed.emplace_back(false);

        // 先找到最左边的点 因为它一定在栅栏上
        int p = 0;
        for (int i = 0; i < n; i++)
            if (trees[i][0] < trees[p][0] ||
                (trees[i][0] == trees[p][0] && trees[i][1] > trees[p][1]))
                p = i;
        ans.emplace_back(trees[p]);  // 栅栏的第一个
        pushed[p] = true;
        int left_top = p;
        int q = (p + 1) % n;

        while (1) {
            // 找到下一个包点
            for (int r = 0; r < n; r++)
                // 如果r在q的右边
                if (r != p && r != q && right(trees[p], trees[q], trees[r]) > 0)
                    q = r;
            if (!pushed[q]) {
                ans.emplace_back(trees[q]);
                pushed[q] = true;
            }

            for (int k = 0; k < n; k++) {
                if (!pushed[k] && k != q && k != p &&
                    right(trees[p], trees[q], trees[k]) == 0) {
                    ans.emplace_back(trees[k]);
                    pushed[k] = true;
                }
            }  // 加入了之后把这条线上的也加入

            if (q == left_top)
                break;
            p = q;
            q = (q + 1) % n;
        }
        return ans;
    }
};

// class Solution2 {
//    public:
//     bool within(vector<vector<int>>& vertex, vector<int>& tree) {}
//     vector<vector<int>> outerTrees(vector<vector<int>>& trees) {}
// };

int main() {
    vector<vector<int>> points{
        {0, 2}, {0, 1}, {0, 0}, {1, 0}, {2, 0}, {1, 1},
    };
    Solution1 s;
    vector<vector<int>> vers = s.outerTrees(points);
    for (auto p : vers)
        cout << p[0] << ", " << p[1] << endl;
    return 0;
    // * * * * * * * * * * * *
    // * * * * * * * * * * * *
    // * * * * * * * * * * * *
    // * * * * * * * * * * * *
    // * * X * * * * * * * * *
    // * * * X * * * * * * * *
    // * * X * X * * * * * * *
    // * * * * * * * * * * * *
    // * * X * * * * * * * * *

    // * * * * * * * * * * * *
    // * * * * * * * * * * * *
    // X * * * * * * * * * * *
    // * X * * * * * * * * * *
    // X X X * * * * * * * * *
}