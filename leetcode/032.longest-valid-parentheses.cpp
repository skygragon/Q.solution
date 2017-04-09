/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses
 *
 * Hard (23.04%)
 * Total Accepted:    89379
 * Total Submissions: 387963
 * Testcase Example:  '""'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 * 
 * 
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), winner = 0;
        vector<int> len(n, 0);

        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') continue;

            int j = i-len[i-1]-1;
            if (s[j] != '(') continue;

            len[i] = 2 + len[i-1];
            if (j >= 1) len[i] += len[j-1];

            winner = max(winner, len[i]);
        }
        return winner;
    }
};
