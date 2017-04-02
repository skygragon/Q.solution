/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching
 *
 * Hard (23.82%)
 * Total Accepted:    123863
 * Total Submissions: 519972
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
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
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
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
            while (j+1 < m && p[j] != '*' && p[j+1] == '*') j += 2;
            x = (j == m);
        } else if (j == m-1 || p[j+1] != '*') {
            if (p[j] == s[i] || p[j] == '.') x = next(i+1, j+1);
            else if (p[j] != s[i]) x = false;
        } else {
            if (p[j] == s[i] || p[j] == '.') x = next(i+1, j) || next(i+1, j+2) || next(i, j+2);
            else x = next(i, j+2);
        }

        return cache[k] = x;
    }

    bool isMatch(string s, string p) {
        this->s = s; this->p = p;
        n = s.size(); m = p.size();

        return next(0, 0);
    }
};
