#include <iostream>
#include <vector>
using namespace std;
class Solution {
   private:
    vector<int> find_line(vector<int>& p1, vector<int>& p2) {
        int x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1];
        if (x1 == 0 && y1 == 0) {
            if (y2 == 0)
                return vector<int>{0, 0, 1};
            if (x2 == 0)
                return vector<int>{0, 1, 0};
            return vector<int>{0, -y2, x2};
        }

        if (x2 == 0 && y2 == 0) {
            if (y1 == 0)
                return vector<int>{0, 0, 1};
            if (x1 == 0)
                return vector<int>{0, 1, 0};
            return vector<int>{0, -y1, x1};
        }

        if (x2 * (y1 - y2) == y2 * (x1 - x2)) {
            if (x1 == 0)
                return vector<int>{0, 1, 0};
            if (y1 == 0)
                return vector<int>{0, 0, 1};
            return vector<int>{0, -y1, x1};
        }

        return vector<int>{x1 * y2 - x2 * y1, y2 - y1, x1 - x2};
    }

   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int curr = 2;
                auto line = find_line(points[i], points[j]);
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    if (line[0] ==
                        line[1] * points[k][0] + line[2] * points[k][1])
                        curr++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}