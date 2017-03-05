/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * Easy (30.86%)
 * Total Accepted:    155293
 * Total Submissions: 503194
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if (strs.empty()) return s;
        if (strs.size() == 1) return strs[0];

        size_t len = strs[0].size();
        for (auto& s : strs) len = min(len, s.size());

        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) return s;
            }
            s.push_back(strs[0][i]);
        }

        return s;
    }
};
