/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching
 *
 * Hard (19.34%)
 * Total Accepted:    84713
 * Total Submissions: 437984
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * 
 */
class Solution {
public:
    string s, p;
    int n, m;
    unordered_map<int, bool> cache;

    bool next(int i, int j) {
        int k = i*m+j;
        if (cache.find(k) != cache.end()) return cache[k];

        bool x = false;

        if (j == m) {
            x = (i == n);
        } else if (i == n) {
            while (j < m && p[j] == '*') ++j;
            x = (j == m);
        } else if (p[j] != '*') {
            if (p[j] == s[i] || p[j] == '?') x = next(i+1, j+1);
        } else {
            x = next(i+1, j) || next(i+1, j+1) || next(i, j+1);
        }

        return cache[k] = x;
    }

    bool isMatch(string s, string p) {
        this->s = s; this->p = p;
        n = s.size(); m = p.size();
        return next(0, 0);
    }
};
