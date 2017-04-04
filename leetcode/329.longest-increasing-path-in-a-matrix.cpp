/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix
 *
 * Hard (35.79%)
 * Total Accepted:    32728
 * Total Submissions: 91382
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * 
 * Example 1:
 * 
 * nums = [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * nums = [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not
 * allowed.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    vector<vector<int>> vv, count;
    int m, n, x;

    int next(int i, int j) {
        if (count[i][j] > 0) return count[i][j];

        int k = 1;
        if (i > 0 && vv[i][j] > vv[i-1][j]) k = max(k, next(i-1, j)+1);
        if (i < m-1 && vv[i][j] > vv[i+1][j]) k = max(k, next(i+1, j)+1);
        if (j > 0 && vv[i][j] > vv[i][j-1]) k = max(k, next(i, j-1)+1);
        if (j < n-1 && vv[i][j] > vv[i][j+1]) k = max(k, next(i, j+1)+1);
        return count[i][j] = k;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); if (m == 0) return 0;
        n = matrix[0].size(); if (n == 0) return 0;

        vv = matrix;
        count.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (count[i][j] > 0) continue;
                x = max(x, next(i, j));
            }

        return x;
    }
};
