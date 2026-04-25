class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool dfs(TrieNode* node, string &word, int i) {
        if (!node) return false;

        if (i == word.size())
            return node->isEnd;

        char c = word[i];

        if (c == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j]) {
                    if (dfs(node->children[j], word, i + 1))
                        return true;
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            return dfs(node->children[idx], word, i + 1);
        }
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */