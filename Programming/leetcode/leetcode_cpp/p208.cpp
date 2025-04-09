#include <iostream>
#include <vector>
using namespace std;

class Trie {
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

    Trie() { root = new node(); }

    node* searchPrefix(string word) {
        node* p = root;
        for (int i = 0; i < word.length(); i++) {
            int pos = word[i] - 'a';
            if (p->children[pos] == nullptr)
                return nullptr;
            p = p->children[pos];
        }
        return p;
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

    bool search(string word) {
        node* p = searchPrefix(word);
        return p != nullptr && p->leaf;
    }

    bool startsWith(string prefix) { return searchPrefix(prefix) != nullptr; }
    ~Trie() {
        for (node* c : root->children)
            delete c;
    }
};