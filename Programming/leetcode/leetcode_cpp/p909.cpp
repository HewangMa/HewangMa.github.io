#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   private:
    vector<int> min_steps;
    int jump_step = 0;
    int n = 0;
    int last = 0;
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1)
            c = n - 1 - c;
        return {n - 1 - r, c};
    }

   public:
    void bfs(vector<vector<int>>& board, int curr) {
        // this part can be simplified
        int row = n - 1 - (curr - 1) / n;
        int col = 0;
        int tag = row % 2 + n % 2;
        if (tag == 0 || tag == 2)  // to left
            col = n - 1 - (curr - 1) % n;
        else  // to right
            col = (curr - 1) % n;
        int jump = board[row][col];

        for (int add = 1; add <= 6 && curr + add <= last; add++)
            if (jump == -1)
                min_steps[curr + add] =
                    min(min_steps[curr + add], min_steps[curr] + 1);

        if (jump_step == 0 && jump != -1) {
            jump_step++;
            // cout << "curr: " << curr << " jump: " << jump << " row: " << row
            //      << " col: " << col << endl;

            min_steps[jump] = min(min_steps[jump], min_steps[curr]);
            bfs(board, board[row][col]);
            jump_step--;
        }
        // cout << "start from: " << curr << ", got info: \n";
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         if (min_steps[i * n + j + 1] != 2147483646)
        //             cout << i * n + j + 1 << ": " << min_steps[i * n + j + 1]
        //                  << ";  ";
        //     cout << endl;
        // }
        // cout << "end ms info: " << endl;
    }

    int snakesAndLadders3(vector<vector<int>>& board) {
        n = board.size();
        last = n * n;
        vector<int> visited(last + 1, 0);
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty()) {
            auto p = q.front();
            for (int i = 1; i <= 6; i++) {
                int next = p.first + i;
                if (next > last)
                    break;
                auto rc = id2rc(p.first, n);
                if (board[rc.first][rc.second] > 0)
                    next = board[rc.first][rc.second];
                if (next == last)
                    return p.second + 1;
                if (visited[next] == 0) {
                    visited[next] = true;
                    q.push({next, p.second + 1});
                }
            }
        }
        return -1;
    }

    int snakesAndLadders2(vector<vector<int>>& board) {
        n = board.size();
        // cout << "board: " << endl;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         cout << board[i][j] << ", ";
        //     cout << endl;
        // }
        // cout << endl;
        last = n * n;
        min_steps.resize(last + 1, 2147483646);
        min_steps[1] = 0;
        int curr = 1;
        while (curr <= last) {
            bfs(board, curr);
            curr++;
        }
        return (min_steps[last] == 2147483646) ? (-1) : (min_steps[last]);
    }

    int snakesAndLadders1(vector<vector<int>>& board) {
        n = board.size();
        last = n * n;
        min_steps.resize(last + 1, 2147483646);
        min_steps[1] = 0;
        for (int add = 1; add <= 6; add++)
            min_steps[min(1 + add, last)] = 1;
        for (int i = 8; i <= last; i++) {
            min_steps[i] = min_steps[i - 1] + 1;
            for (int from = 2; from < last; from++) {
                if (i - from <= 6)
                    min_steps[i] = min(min_steps[i], min_steps[from] + 1);

                int row = n - 1 - (from - 1) / n;
                int col = 0;
                int tag = (row % 2) + (n % 2);
                if (tag == 0 || tag == 2)  // to left
                    col = n - 1 - (from - 1) % n;
                else  // to right
                    col = (from - 1) % n;

                if (board[row][col] == i)
                    min_steps[i] = min(min_steps[i], min_steps[from]);
            }
            if (i == last)
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        cout << i * n + j + 1 << ": "
                             << min_steps[i * n + j + 1] << ";  ";
                    cout << endl;
                }
        }
        return min_steps[last];
    }
};
int main() {
    vector<vector<int>> board1;
    for (int i = 0; i < 6; i++)
        board1.emplace_back(vector<int>(6, -1));
    board1[3][1] = 35;
    board1[3][4] = 13;
    board1[5][1] = 15;

    vector<vector<int>> board2;
    for (int i = 0; i < 3; i++)
        board2.emplace_back(vector<int>(3, 1));
    board2[0][2] = -1;
    board2[2][0] = -1;

    vector<vector<int>> board3;
    for (int i = 0; i < 3; i++)
        board3.emplace_back(vector<int>(3, -1));

    board3[1][1] = 9;
    board3[1][2] = 8;
    board3[2][1] = 8;
    board3[2][2] = 9;

    Solution s;
    cout << "result: " << s.snakesAndLadders3(board3);
    return 0;
}

//* T * F * * F * * * F * * * T
//* T * F * * T * * * T * * * T
//* T * F * * T * * * T * * * T
//* T * F * * T * * * T * * * T
//* T * F * * T * * * T * * * T
//* T * F * * T * * * T * * * T
//* T * F * * T * * * T * * * T
//* T * F * * T * * * T * * * T
//* T * F * * T * * * T * * * T