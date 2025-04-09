#include <iostream>
#include <string>
#include <vector>
using namespace std;
class WordDictionary {
   public:
    class node {
       public:
        bool leaf;
        vector<node*> children;
        node() : leaf(false), children(26) {}
        ~node() {
            for (auto child : children)
                delete child;
        }
    };
    node* root;

    bool dfs(node* start, string word) {
        if (start == nullptr)
            return false;
        if (word.length() == 0)
            return start->leaf;
        
        for (int i = 0; i < word.length(); i++) {
            string sub = word.substr(i + 1, word.length() - i - 1);
            if (word[i] == '.') {
                int j = 0;
                for (; j < 26; j++) {
                    if (dfs(start->children[j], sub))
                        return true;
                }
                if (j == 26)
                    return false;
            } else {
                int pos = word[i] - 'a';
                if (start->children[pos] == nullptr)
                    return false;
                return dfs(start->children[pos], sub);
            }
        }
        return false;
    }

    WordDictionary() {
        root = new node();
        root->leaf = true;
    }
    void insert(string word) {
        node* p = root;
        for (int i = 0; i < word.length(); i++) {
            int pos = word[i] - 'a';
            if (p->children[pos] == nullptr)
                p->children[pos] = new node();
            p = p->children[pos];
        }
        p->leaf = true;
    }
    void addWord(string word) {
        node* p = root;
        for (char c : word) {
            int pos = c - 'a';
            if (p->children[pos] == nullptr)
                p->children[pos] = new node();
            p = p->children[pos];
        }
        p->leaf = true;
    }

    bool search(string word) { return dfs(root, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */