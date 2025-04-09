#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution0 {
   public:
    string get_element(string& s) {
        int i = 0;
        while (i < s.length() && s[i] != ',')
            i++;
        string ret = s.substr(0, i);
        if (i + 1 < s.length())
            s = s.substr(i + 1, s.length());
        else
            s = "";
        return ret;
    }
    vector<string> get_first_three(string pre) {
        vector<string> first;
        for (int i = 0; i < 3; i++) {
            if (pre.length() < 1)
                break;
            string head = get_element(pre);
            first.push_back(head);
        }
        return first;
    }
    bool isValidSerialization(string preorder) {
        vector<string> first = get_first_three(preorder);
        if (first.size() < 3)
            return false;
        if (first[0] == "#")
            return false;
        if (first[1] == "#" && first[2] == "#")
            return true;
        if (first[1] == "#" && first[2] != "#") {
            preorder = first[2] + "," + preorder;
            return isValidSerialization(preorder);
        }
        if (first[1] != "#" && first[2] == "#") {
            preorder = first[1] + "," + preorder;
            return isValidSerialization(preorder);
        }
        if (first[1] != "#" && first[2] != "#") {
            string left = first[1] + "," + preorder;
            bool left_valid = isValidSerialization(left);
            string right = first[2] + "," + left;
            return left_valid && isValidSerialization(right);
        }
        return true;
    }
};

class Solution {
   public:
    string get_element(string& s) {
        int i = 0;
        while (i < s.length() && s[i] != ',')
            i++;
        string ret = s.substr(0, i);
        if (i + 1 < s.length())
            s = s.substr(i + 1, s.length());
        else
            s = "";
        return ret;
    }
    // 使用stack不如使用vector
    void handle_stack(stack<string>& st) {
        while (st.size() >= 3) {
            vector<string> temp;
            for (int i = 0; i < 3; i++) {
                temp.emplace_back(st.top());
                st.pop();
            }
            if (temp[0] == "#" && temp[1] == "#" && temp[2] != "#") {
                st.push("#");
            } else {
                for (int i = 0; i < 3; i++)
                    st.push(temp[2 - i]);
                return;
            }
        }
    }
    bool isValidSerialization(string preorder) {
        stack<string> st;
        while (preorder.length() > 0) {
            string x = get_element(preorder);
            st.push(x);
            handle_stack(st);
        }
        return st.size() == 1 && st.top() == "#";
    }
};

int main() {
    Solution s = Solution();
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    // cout << preorder.substr(233, 2) << endl;
    cout << s.isValidSerialization(preorder) << endl;
    return 0;
}