#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    vector<TrieNode*> children;
    
    TrieNode(char data) {
        this -> data = data;
        children.assign(26, nullptr);
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
        return true;
    }
    
    bool patternMatching(vector<string> vect, string pattern) {
        for (int i = 0; i < vect.size(); ++i) {
            // get each word 
            string word = vect[i];
            for (int j = 0; j < word.length(); ++j) {
                // insert word along with all it's suffixes
                // ex: band
                // first band will be inserted, then and, then nd and finally d.
                insertWord(word.substr(j));
            }
        }
        return search(pattern);
    }
};