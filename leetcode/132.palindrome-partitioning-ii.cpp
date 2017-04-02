/*
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii
 *
 * Hard (23.61%)
 * Total Accepted:    65332
 * Total Submissions: 276681
 * Testcase Example:  '"aab"'
 *
 * 
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * 
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced
 * using 1 cut.
 * 
 */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> p(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) p[i][i] = true;
        for (int i = n-1; i >= 0; --i)
            for (int j = i+1; j < n; ++j) {
                if (s[i] != s[j]) continue;
                if (i+1 == j) p[i][j] = true;
                else if (i+1 <= j-1) p[i][j] = p[i+1][j-1];
            }

        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            if (p[0][i]) { dp[i] = 0; continue; }

            dp[i] = min(i, dp[i-1]+1);
            for (int k = 1; k < i && dp[i] > 0; ++k) {
                if (!p[k][i]) continue;
                dp[i] = min(dp[i], dp[k-1]+1);
            }
        }

        return dp[n-1];
    }
};
