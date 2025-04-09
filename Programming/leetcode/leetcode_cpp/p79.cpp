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
class Solution {
   private:
    int m;
    int n;
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   public:
    bool find_word(vector<vector<char>>& board, string word, int si, int sj) {
        char c = board[si][sj];
        if (word.length() == 0)
            return true;
        if (c != word[0])
            return false;
        if (word.length() == 1)
            return true;
        board[si][sj] = '#';
        string sub = word.substr(1, word.length());
        for (int i = 0; i < 4; i++) {
            int ni = si + dirs[i][0];
            int nj = sj + dirs[i][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] == '#')
                continue;
            if (find_word(board, sub, ni, nj))
                return true;
        }
        board[si][sj] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<string> ret;
        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0])
                    if (find_word(board, word, i, j))
                        return true;
        return false;
    }
};
