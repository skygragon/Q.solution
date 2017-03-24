/*
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix
 *
 * Medium (32.41%)
 * Total Accepted:    2092
 * Total Submissions: 6448
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * Example 1: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 
 * Example 2: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 1 1 1
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 1 2 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); if (m == 0) return matrix;
        int n = matrix[0].size(); if (n == 0) return matrix;

        using P = pair<int, int>;
        vector<P> cur;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) continue;
                if ((i > 0   && matrix[i-1][j] == 0) ||
                    (i < m-1 && matrix[i+1][j] == 0) ||
                    (j > 0   && matrix[i][j-1] == 0) ||
                    (j < n-1 && matrix[i][j+1] == 0)) {
                    cur.push_back({i,j});
                }
                matrix[i][j] = -1;
            }

        int x = 1, i, j;
        while (!cur.empty()) {
            vector<P> next;
            for (auto &p : cur) {
                i = p.first; j = p.second;
                if (matrix[i][j] > 0) continue;

                if (i > 0   && matrix[i-1][j] < 0) next.push_back({i-1,j});
                if (i < m-1 && matrix[i+1][j] < 0) next.push_back({i+1,j});
                if (j > 0   && matrix[i][j-1] < 0) next.push_back({i,j-1});
                if (j < n-1 && matrix[i][j+1] < 0) next.push_back({i,j+1});

                matrix[i][j] = x;
            }
            cur.swap(next);
            ++x;
        }
        return matrix;
    }
};
