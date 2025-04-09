#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class LockingTree {
   private:
    unordered_map<int, int> locked;
    vector<int> parent;
    int n;

   public:
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        this->n = parent.size();
    }

    bool lock(int num, int user) {
        if (locked.count(num) == 0) {
            locked[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (locked.count(num) > 0 && locked[num] == user) {
            locked.erase(num);
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (locked.count(num) > 0)
            return false;
        vector<int> locked_sons = {};

        // 祖先节点没有被锁住的
        int p = num;
        while (p != -1) {
            if (locked.count(p) > 0)
                return false;
            p = parent[p];
        }

        // 加入所有被锁住的孩子
        for (int i = 0; i < n; i++) {
            if (locked.count(i) == 0)
                continue;
            p = i;
            while (p != -1) {
                p = parent[p];
                if (p == num)
                    break;
            }
            if (p == num)
                locked_sons.push_back(i);
        }
        if (locked_sons.size() == 0)
            return false;

        locked[num] = user;
        for (int i : locked_sons)
            locked.erase(i);
        return true;
    }
};
