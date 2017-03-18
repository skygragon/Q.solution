/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring
 *
 * Medium (24.90%)
 * Total Accepted:    178994
 * Total Submissions: 718882
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string s2 = "#";
        for (auto c : s) { s2 += c; s2 += "#"; }
        s.swap(s2);

        int n = s.size();
        int last_i = -1, last_e = -1, max_i = -1;

        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) {
            int x = 0;
            if (i > last_i && i <= last_e) x = min(v[2*last_i-i], last_e-i);

            int j = i-x-1, k = i+x+1;
            while (j >= 0 && k < n && s[j] == s[k]) { --j; ++k; ++x; }

            v[i] = x;
            if (i+x > last_e) { last_i = i; last_e = i+x; }
            if (max_i == -1 || x > v[max_i]) max_i = i;
        }

        return s2.substr(max_i/2-v[max_i]/2, v[max_i]);
    }
};
