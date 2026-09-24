#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<char, Node*> child;
    bool is_end = false;
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;

        for(char c : word) {
            if(cur->child.find(c) == cur->child.end()) {
                cur->child[c] = new Node();
            }

            cur = cur->child[c];
        }

        cur->is_end = true;
    }

    bool dfs(const string& word, int i, Node* cur) {
        if(i == word.size())
            return cur->is_end;

        if(word[i] != '.') {
            if(cur->child.find(word[i]) == cur->child.end())
                return false;

            return dfs(word, i + 1, cur->child[word[i]]);
        }

        for(auto& [c, next] : cur->child) {
            if(dfs(word, i + 1, next))
                return true;
        }

        return false;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};