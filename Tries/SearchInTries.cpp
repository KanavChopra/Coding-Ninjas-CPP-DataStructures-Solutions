#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;
    
    TrieNode(char data) {
        this -> data = data;
        children.assign(26, nullptr);
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;
    public:
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(string word) {
        TrieNode* curr = root;
        for (auto& ch : word) {
            ch -= 'a';
            if (!curr -> children[ch]) {
                curr -> children[ch] = new TrieNode(ch);
            }
            curr = curr -> children[ch];
        }
        curr -> isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (auto& ch : word) {
            ch -= 'a';
            if (!curr -> children[ch]) {
                return false;
            }
            curr = curr -> children[ch];
        }
        return curr -> isTerminal;
    }
};