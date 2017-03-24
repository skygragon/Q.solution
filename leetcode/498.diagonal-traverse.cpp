/*
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse
 *
 * Medium (46.25%)
 * Total Accepted:    3607
 * Total Submissions: 7790
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image. 
 * 
 * 
 * Example:
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output:  [1,2,4,7,5,3,6,8,9]
 * Explanation:
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 * 
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> v;

        int m = matrix.size(); if (m == 0) return v;
        int n = matrix[0].size(); if (n == 0) return v;

        int x = 0, i, j;
        while (v.size() < m*n) {
            if (x % 2) {
                i = 0; j = x-i;
                while (j >= 0) {
                    if (i < m && j < n) v.push_back(matrix[i][j]);
                    ++i; --j;
                }
            } else {
                j = 0; i = x-j;
                while (i >= 0) {
                    if (i < m && j < n) v.push_back(matrix[i][j]);
                    ++j; --i;
                }
            }
            ++x;
        }

        return v;
    }
};
