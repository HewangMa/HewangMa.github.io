#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ret;
        for (int i = 1; i < mountain.size() - 1; i++)
            if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1])
                ret.emplace_back(mountain[i]);
        return ret;
    }
};