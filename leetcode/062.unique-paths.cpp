/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths
 *
 * Medium (39.70%)
 * Total Accepted:    125395
 * Total Submissions: 315842
 * Testcase Example:  '1\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vv(m);
        for (auto& v : vv) v.resize(n, 1);

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                vv[i][j] = vv[i-1][j] + vv[i][j-1];
            }

        return vv[m-1][n-1];
    }
};
