class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this -> count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root -> isTerminal) {
                root -> isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
            root -> childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this -> count++;
        }
    }
    
    bool search(TrieNode* root, string word) {
        if (word.length() == 0 || (word.length() == 1 && root -> isTerminal)) {
            return true;
        }
        if (root -> children[word[0] - 'a']) {
            return search(root -> children[word[0] - 'a'], word.substr(1));
        } else {
            return false;
        }
    }
    
    bool search(string word) {
        return search(root, word);
    }

    /*..................... Palindrome Pair................... */

    bool isPalindrome(string word) {
        int start = 0;
        int end = word.length() - 1;
        while (start < end) {
            if (word[start] != word[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    bool searchPalindrome(vector<string> words) {
        for (auto& word : words) {
            reverse(word.begin(), word.end());
            if (search(word)) {
                return true;
            } else if (isPalindrome(word)) {
                return true;
            }
        }
        return false;
    }
        
    bool isPalindromePair(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            add(words[i]);
        }
        return searchPalindrome(words);
    }
};