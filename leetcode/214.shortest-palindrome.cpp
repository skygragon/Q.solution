/*
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome
 *
 * Hard (23.48%)
 * Total Accepted:    36870
 * Total Submissions: 156928
 * Testcase Example:  '"aacecaaa"'
 *
 * 
 * Given a string S, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 * 
 * 
 * For example: 
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Thanks to @Freezen for additional test cases.
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(), i;
        if (n < 2) return s;

        string s1 = s;
        reverse(s1.begin(), s1.end());

        for (i = n; i >= 1; --i) if (s.substr(0, i) == s1.substr(n-i)) break;

        string p = s1.substr(0, n-i);
        return p + s;
    }
};
