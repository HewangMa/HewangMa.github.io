#include <math.h>
#include <algorithm>
#include <hash_map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    char change(char c) {
        if (c == 'a')
            return 'z';
        else
            return c - 1;
    }
    string smallestString(string s) {
        int n = s.size();
        int start = 0;
        while (start < n && s[start] == 'a')
            start++;
        int end = start;
        while (end < n && s[end] != 'a')
            end++;
        cout << "s = " << start << " e = " << end << endl;
        if (start == end)
            s[n - 1] = change(s[n - 1]);
        for (int i = start; i < end && i < n; i++)
            s[i] = change(s[i]);
        return s;
    }
};