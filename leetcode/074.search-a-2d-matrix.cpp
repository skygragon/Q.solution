/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix
 *
 * Medium (35.38%)
 * Total Accepted:    112498
 * Total Submissions: 317932
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * 
 * 
 * Given target = 3, return true.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int i = 0, j = m*n-1;
        while (i <= j) {
            int k = i+(j-i)/2;
            int cur = matrix[k / n][k % n];
            if (cur == target) return true;
            else if (cur > target) --j;
            else ++i;
        }
        return false;
    }
};
