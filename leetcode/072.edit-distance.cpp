/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance
 *
 * Hard (30.97%)
 * Total Accepted:    81789
 * Total Submissions: 263855
 * Testcase Example:  '""\n""'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * 
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> vv(n1+1);
        for (auto &v : vv) v.resize(n2+1, 0);

        for (int i = 0; i <= n1; ++i) vv[i][0] = i;
        for (int i = 0; i <= n2; ++i) vv[0][i] = i;

        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    vv[i][j] = vv[i-1][j-1];
                } else {
                    vv[i][j] = min(vv[i][j-1], vv[i-1][j]);
                    vv[i][j] = min(vv[i][j], vv[i-1][j-1]) + 1;
                }
            }
        return vv[n1][n2];
    }
};
