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
class Trie {
   public:
    string word;
    unordered_map<char, Trie*> children;
    Trie() { word = ""; }
};

class Solution {
   private:
    int m;
    int n;
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    set<string> st;
    void insert_trie(Trie* root, string word) {
        Trie* node = root;
        for (char c : word) {
            if (node->children.count(c) == 0)
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->word = word;
    }
    void dfs(vector<vector<char>>& board, int x, int y, Trie* root) {
        char c = board[x][y];
        if (root == nullptr || !root->children.count(c))
            return;
        Trie* next = root->children[c];
        if (next->word.size() > 0) {
            st.insert(next->word);
            next->word == "";
        }
        if (!next->children.empty()) {
            board[x][y] = '#';
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                    board[nx][ny] == '#')
                    continue;
                dfs(board, nx, ny, root);
            }
            board[x][y] = c;
        }
        if (next->children.empty())
            root->children.erase(c);
    }

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> ret;
        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        Trie* root = new Trie();
        for (string word : words)
            insert_trie(root, word);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                dfs(board, i, j, root);
        }
        for (string word : st)
            ret.emplace_back(word);
        return ret;
    }
};

class Solution1 {
   private:
    int m;
    int n;

   public:
    bool find_word(vector<vector<char>>& board,
                   vector<vector<int>>& visited,
                   string word,
                   int si,
                   int sj) {
        if (word.length() == 0)
            return true;
        if (board[si][sj] != word[0])
            return false;
        if (word.length() == 1)
            return true;
        visited[si][sj] = 1;
        queue<pair<int, int>> q;
        if (si + 1 < m && visited[si + 1][sj] == 0)
            q.push({si + 1, sj});
        if (si - 1 >= 0 && visited[si - 1][sj] == 0)
            q.push({si - 1, sj});
        if (sj + 1 < n && visited[si][sj + 1] == 0)
            q.push({si, sj + 1});
        if (sj - 1 >= 0 && visited[si][sj - 1] == 0)
            q.push({si, sj - 1});
        string sub = word.substr(1, word.length());
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            if (find_word(board, visited, sub, pos.first, pos.second))
                return true;
            else
                visited[pos.first][pos.second] = 0;
        }
        visited[si][sj] = 0;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        set<string> ret;
        vector<string> retv;
        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        for (string word : words) {
            vector<vector<int>> visited(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == word[0])
                        if (find_word(board, visited, word, i, j))
                            ret.insert(word);
                }
        }
        for (auto word : ret)
            retv.emplace_back(word);
        return retv;
    }
};

int main() {
    vector<vector<char>> board1{{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};
    vector<string> words1{"oath", "pea", "eat", "rain"};
    vector<vector<char>> board2{
        {'a', 'b', 'c'}, {'a', 'e', 'd'}, {'a', 'f', 'g'}};
    vector<string> words2{"abcdefg", "gfedcbaaa", "eaabcdgfa",
                          "befa",    "dgc",       "ade"};
    Solution s;
    auto ans = s.findWords(board2, words2);
    for (auto one : ans)
        cout << one << endl;
    return 0;
}