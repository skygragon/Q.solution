/*
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design
 *
 * Medium (21.05%)
 * Total Accepted:    47803
 * Total Submissions: 226964
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * 
 * For example:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 * 
 * click to show hint.
 * 
 * You should be familiar with how a Trie works. If not, please work on this
 * problem: Implement Trie (Prefix Tree) first.
 * 
 */
class Trie {
public:
    struct Node {
        char c;
        bool leaf;
        Node* next[26] { nullptr };

        Node(char _c = '\0', bool _l = false) : c(_c), leaf(_l) {}
        ~Node() { for (int i = 0; i < 26; ++i) delete next[i]; }
    };

    Node *root;

    Trie() { root = new Node(); }
    ~Trie() { delete root; }

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

    bool search(Node* p, string s) {
        if (s.empty()) return p && p->leaf;
        if (!p) return false;

        char c = s[0];
        s = s.substr(1);

        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (search(p->next[i], s)) return true;
            }
            return false;
        } else {
            return search(p->next[c-'a'], s);
        }
    }

    bool search(string word) {
        return search(root, word);
    }
};
class WordDictionary {
public:
    Trie trie;

    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
