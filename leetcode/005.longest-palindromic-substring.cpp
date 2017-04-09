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

        int b = -1, e = -1, winner = -1, n = s2.size();
        vector<int> len(n, 0);

        for (int i = 0; i < n; ++i) {
            int x = 0;
            if (i > b && i <= e) x = min(len[2*b-i], e-i);

            for (int j = i-x-1, k = i+x+1;
                 j >= 0 && k < n && s2[j] == s2[k];
                 --j, ++k, ++x);

            len[i] = x;

            if (i+x > e) { b = i; e = i+x; }
            if (winner == -1 || x > len[winner]) winner = i;
        }

        return s.substr(winner/2 - len[winner]/2, len[winner]);
    }
};
