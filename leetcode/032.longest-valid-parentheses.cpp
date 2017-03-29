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
        int n = s.size(), x = 0;
        vector<int> v(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') continue;

            if (s[i-1] == '(') {
                v[i] = 2 + (i>=2 ? v[i-2] : 0);
            } else if (v[i-1] > 0) {
                int j = i-v[i-1]-1;
                if (s[j] == '(')
                    v[i] = 2 + v[i-1] + (j>=1 ? v[j-1] : 0);
            }

            x = max(x, v[i]);
        }

        return x;
    }
};
