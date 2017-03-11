/*
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image
 *
 * Medium (37.53%)
 * Total Accepted:    100913
 * Total Submissions: 268889
 * Testcase Example:  '[[1]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n-i-1; ++j)
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);

        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-1-i][j]);
    }
};
