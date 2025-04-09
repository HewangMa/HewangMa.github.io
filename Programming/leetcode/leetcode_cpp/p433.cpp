#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
   private:
    vector<vector<int>> gragh;
    bool one_diff(string s, string t) {
        int diff = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] != t[i])
                diff++;
        return diff == 1;
    }

   public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene)
            return 0;
        int n = bank.size();
        vector<int> start_neighbors;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (one_diff(bank[i], startGene))
                q.push({i, 1});
            vector<int> neighbors;
            for (int j = 0; j < n; j++)
                if (one_diff(bank[i], bank[j]))
                    neighbors.emplace_back(j);
            gragh.emplace_back(neighbors);
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.second > n + 1)
                return -1;
            if (bank[p.first] == endGene)
                return p.second;
            for (auto nei : gragh[p.first])
                q.push({nei, p.second + 1});
        }
        return -1;
    }
};