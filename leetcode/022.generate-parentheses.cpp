/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses
 *
 * Medium (42.62%)
 * Total Accepted:    131413
 * Total Submissions: 308324
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string L = "(", R = ")", P = "()";

        vector<vector<string>> vv(n+1);
        vv[1].push_back(P);

        for (int i = 2; i <= n; ++i) {
            unordered_set<string> ss;
            for (auto s : vv[i-1]) ss.insert(L + s + R);
            for (int j = 1; j < i; ++j) {
                for (auto s1: vv[j])
                    for (auto s2: vv[i-j]) {
                        ss.insert(s1+s2);
                        ss.insert(s2+s1);
                    }
            }
            vv[i].insert(vv[i].end(), ss.begin(), ss.end());
        }
        return vv[n];
    }
};
