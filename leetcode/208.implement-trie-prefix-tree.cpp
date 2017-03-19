/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree
 *
 * Medium (26.55%)
 * Total Accepted:    67771
 * Total Submissions: 255135
 * Testcase Example:  '["Trie","search"]\n[[],["a"]]'
 *
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 */
class Trie {
public:
    struct Node {
        char c;
        bool leaf;
        Node* next[26] { nullptr };

        Node(char _c = '\0', bool _l = false) : c(_c), leaf(_l) {}
        ~Node() {
            for (int i = 0; i < 26; ++i) delete next[i];
        }
    };

    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for (auto c : word) {
            if (!p->next[c-'a']) {
                Node* p1 = new Node(c, false);
                p->next[c-'a'] = p1;
            }
            p = p->next[c-'a'];
        }
        p->leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *p = root;
        for (auto c : word) {
            if (!p->next[c-'a']) return false;
            p = p->next[c-'a'];
        }
        return p->leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *p = root;
        for (auto c : prefix) {
            if (!p->next[c-'a']) return false;
            p = p->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
