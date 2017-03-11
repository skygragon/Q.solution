/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum
 *
 * Medium (37.50%)
 * Total Accepted:    101711
 * Total Submissions: 271189
 * Testcase Example:  '[[0]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto vv = grid;
        for (int i = 1; i < m; ++i) vv[i][0] = vv[i-1][0] + grid[i][0];
        for (int j = 1; j < n; ++j) vv[0][j] = vv[0][j-1] + grid[0][j];

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                vv[i][j] = min(vv[i-1][j], vv[i][j-1]) + grid[i][j];

        return vv[m-1][n-1];
    }
};
