/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring
 *
 * Hard (24.42%)
 * Total Accepted:    93944
 * Total Submissions: 384542
 * Testcase Example:  '"a"\n"a"'
 *
 * 
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * 
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * 
 * 
 * Minimum window is "BANC".
 * 
 * 
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * 
 * 
 * If there are multiple such windows, you are guaranteed that there will
 * always be only one unique minimum window in S.
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cur, need;
        for (auto c : t) { cur[c] = 0; ++need[c]; }

        string window;
        int missing = t.size(), j = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (cur.find(c) == cur.end()) continue;

            if (++cur[c] <= need[c]) --missing;

            for (;j < i; ++j) {
                char c = s[j];
                if (cur.find(c) == cur.end()) continue;

                if (cur[c] <= need[c]) break;
                if (--cur[c] < need[c]) ++missing;
            }

            if (missing == 0) {
                if (window.empty() || i-j+1 < window.size())
                    window = s.substr(j, i-j+1);
            }
        }

        return window;
    }
};
