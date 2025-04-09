#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int n = secret.length();
        vector<int> appear(10, 0);
        for (int i = 0; i < n; i++) {
            appear[secret[i] - '0']++;
            if (secret[i] == guess[i]) {
                A++;
                appear[secret[i] - '0']--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (appear[guess[i] - '0'] > 0 && secret[i] != guess[i]) {
                B++;
                appear[guess[i] - '0']--;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};