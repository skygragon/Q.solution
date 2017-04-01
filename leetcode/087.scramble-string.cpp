/*
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string
 *
 * Hard (28.56%)
 * Total Accepted:    60275
 * Total Submissions: 211039
 * Testcase Example:  '"a"\n"a"'
 *
 * 
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 * 
 * 
 * Below is one possible representation of s1 = "great":
 * 
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 * 
 * 
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 * 
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 * 
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 * 
 */
class Solution {
public:
    bool isSame(const string &s1, const string &s2) {
        unordered_map<char, int> m;
        for (auto c : s1) ++m[c];
        for (auto c : s2) if (--m[c] == 0) m.erase(c);
        return m.empty();
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n == 0) return true;
        if (n == 1) return s1 == s2;
        if (!isSame(s1, s2)) return false;

        bool found = false;
        for (int i = 1; i < n; ++i) {
            found = isScramble(s1.substr(0, i), s2.substr(n-i)) &&
                    isScramble(s1.substr(i), s2.substr(0, n-i));
            if (found) return true;

            found = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i), s2.substr(i));
            if (found) return true;
        }

        return false;
    }
};
