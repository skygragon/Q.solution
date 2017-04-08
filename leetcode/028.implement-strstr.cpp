/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * Easy (27.26%)
 * Total Accepted:    162764
 * Total Submissions: 596971
 * Testcase Example:  '""\n""'
 *
 * 
 * Implement strStr().
 * 
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 */
class Solution {
public:
    int strStr(string haystack, string s) {
        if (s.empty()) return 0;
        if (haystack.empty()) return -1;

        int n = haystack.size(), m = s.size(), i, j, k;

        // generate next[]
        vector<int> next(m, -1);
        i = 0; k = -1;
        while (i < m-1) {
            if (k == -1 || s[i] == s[k]) {
                next[++i] = ++k;
            } else {
                k = next[k];
            }
        }

        // do match
        i = j = 0;
        while (i < n) {
            if (j == -1 || haystack[i] == s[j]) { ++i; ++j; }
            else j = next[j];

            if (j == m) return i-j;
        }

        return -1;
    }
};
