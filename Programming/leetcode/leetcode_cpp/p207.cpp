#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        set<int> in_edge;
        for (int i = 0; i < n; i++)
            in_edge.insert(i);
        vector<int> in_degree(numCourses, 0);
        vector<int> out_degree(numCourses, 0);
        for (int e : in_edge) {
            int from = prerequisites[e][1];
            int to = prerequisites[e][0];
            in_degree[to]++;
            out_degree[from]++;
        }
        while (in_edge.size() > 0) {
            int init_size = in_edge.size();
            for (int e : in_edge) {
                int from = prerequisites[e][1];
                int to = prerequisites[e][0];
                if (in_degree[from] == 0) {
                    in_degree[to]--;
                    out_degree[from]--;
                    in_edge.erase(e);
                    break;
                }
            }
            if (init_size == in_edge.size())
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << sizeof(s) << endl;
    vector<vector<int>> prerequisites;
    prerequisites.emplace_back(vector<int>{1, 0});
    prerequisites.emplace_back(vector<int>{2, 1});
    prerequisites.emplace_back(vector<int>{3, 2});
    prerequisites.emplace_back(vector<int>{4, 2});
    prerequisites.emplace_back(vector<int>{4, 3});
    prerequisites.emplace_back(vector<int>{3, 4});
    for (auto p : prerequisites)
        cout << p[0] << ' ' << p[1] << endl;
    cout << "hello?" << s.canFinish(5, prerequisites);
    return 0;
}
