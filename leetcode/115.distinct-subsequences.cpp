/*
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences
 *
 * Hard (30.86%)
 * Total Accepted:    65558
 * Total Submissions: 212446
 * Testcase Example:  '""\n"a"'
 *
 * 
 * Given a string S and a string T, count the number of distinct subsequences
 * of T in S.
 * 
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * 
 * 
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * 
 * 
 * Return 3.
 * 
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(); if (n == 0) return 0;
        int m = t.size(); if (m == 0) return 0;

        vector<vector<int>> vv(n+1, vector<int>(m+1, 0));
        for (int i = 0; i <= n; ++i) vv[i][0] = 1;

        for (int j = 1; j <= m; ++j)
            for (int i = j; i <= n; ++i) {
                if (s[i-1] == t[j-1]) vv[i][j] += vv[i-1][j-1];
                if (i-1 >= j) vv[i][j] += vv[i-1][j];
            }

        return vv[n][m];
    }
};
