/*
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii
 *
 * Medium (31.11%)
 * Total Accepted:    93319
 * Total Submissions: 299989
 * Testcase Example:  '[[0]]'
 *
 * Follow up for "Unique Paths":
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * 
 * [
 * ⁠ [0,0,0],
 * ⁠ [0,1,0],
 * ⁠ [0,0,0]
 * ]
 * 
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;

        vector<vector<int>> vv(m);
        for (auto &v : vv) v.resize(n, 0);
        vv[0][0] = 1;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    vv[i][j] = 0;
                else {
                    if (i >= 1) vv[i][j] += vv[i-1][j];
                    if (j >= 1) vv[i][j] += vv[i][j-1];
                }
            }

        return vv[m-1][n-1];
    }
};
