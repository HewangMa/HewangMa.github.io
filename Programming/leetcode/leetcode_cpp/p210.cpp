#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        int n = prerequisites.size();
        set<int> in_edge;
        for (int i = 0; i < n; i++)
            in_edge.insert(i);
        vector<int> in_degree(numCourses, 0);
        for (int e : in_edge) {
            int to = prerequisites[e][0];
            in_degree[to]++;
        }
        while (in_edge.size() > 0) {
            int init_size = in_edge.size();
            for (int e : in_edge) {
                int from = prerequisites[e][1];
                int to = prerequisites[e][0];
                if (in_degree[from] == 0) {
                    in_degree[to]--;
                    if (find(ret.begin(), ret.end(), from) == ret.end())
                        ret.emplace_back(from);
                    in_edge.erase(e);
                    break;
                }
            }
            if (init_size == in_edge.size())
                return vector<int>{};
        }
        for (int i = 0; i < numCourses; i++)
            if (find(ret.begin(), ret.end(), i) == ret.end())
                ret.emplace_back(i);
        return ret;
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
    for (auto p : prerequisites)
        cout << p[0] << ' ' << p[1] << endl;
    vector<int> order = s.findOrder(5, prerequisites);
    for (int p : order)
        cout << p << ", ";
    return 0;
}
