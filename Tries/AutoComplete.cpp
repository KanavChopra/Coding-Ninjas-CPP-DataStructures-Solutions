class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this- > count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        if (word.size() == 0) {
            if (!root -> isTerminal) {
                root -> isTerminal = true;
                return true;
            } else {
                return false;
            }
        }
        int index = word[0] - 'a';
        TrieNode *child;

        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this -> count++;
        }
    }
    
    TrieNode* search(TrieNode* root, string word) {
        if (word.size() == 0) {
            return root;
        }
        if (root -> children[word[0] - 'a']) {
            return search(root -> children[word[0] - 'a'], word.substr(1));
        }
    }
    
    TrieNode* search(string word) {
        return search(root, word);
    }
    
    void autoCompleteHelper(TrieNode* root, string word) {
        if (!root) {
            return;
        }
        if (root -> isTerminal) {
            cout << word << '\n';
        }
        for (int i = 0; i < 26; ++i) {
            if (root -> children[i] != NULL) {
                autoCompleteHelper(root -> children[i], word + root -> children[i] -> data);
            }
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        for (auto& word : input) {
            insertWord(word);
        }
        TrieNode* root = search(pattern);
        autoCompleteHelper(root, pattern);
    }
};
