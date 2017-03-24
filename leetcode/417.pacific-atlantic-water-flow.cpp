/*
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow
 *
 * Medium (33.07%)
 * Total Accepted:    11074
 * Total Submissions: 33483
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * Example:
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 */
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        using P = pair<int, int>;
        vector<P> v;
        int m = matrix.size(); if (m == 0) return v;
        int n = matrix[0].size(); if (n == 0) return v;

        vector<vector<bool>> pvv(m, vector<bool>(n, false));
        vector<vector<bool>> avv(m, vector<bool>(n, false));

        stack<P> ps;
        for (int i = 0; i < m; ++i) ps.push({i, 0});
        for (int j = 0; j < n; ++j) ps.push({0, j});

        while (!ps.empty()) {
            auto p = ps.top(); ps.pop();
            int x = p.first, y = p.second, k = matrix[x][y];
            if (pvv[x][y]) continue;
            pvv[x][y] = true;

            if (x > 0   && !pvv[x-1][y] && matrix[x-1][y] >= k) ps.push({x-1, y});
            if (x < m-1 && !pvv[x+1][y] && matrix[x+1][y] >= k) ps.push({x+1, y});
            if (y > 0   && !pvv[x][y-1] && matrix[x][y-1] >= k) ps.push({x, y-1});
            if (y < n-1 && !pvv[x][y+1] && matrix[x][y+1] >= k) ps.push({x, y+1});
        }

        stack<P> as;
        for (int i = 0; i < m; ++i) as.push({i, n-1});
        for (int j = 0; j < n; ++j) as.push({m-1, j});

        while (!as.empty()) {
            auto p = as.top(); as.pop();
            int x = p.first, y = p.second, k = matrix[x][y];
            if (avv[x][y]) continue;
            avv[x][y] = true;

            if (x > 0   && !avv[x-1][y] && matrix[x-1][y] >= k) as.push({x-1, y});
            if (x < m-1 && !avv[x+1][y] && matrix[x+1][y] >= k) as.push({x+1, y});
            if (y > 0   && !avv[x][y-1] && matrix[x][y-1] >= k) as.push({x, y-1});
            if (y < n-1 && !avv[x][y+1] && matrix[x][y+1] >= k) as.push({x, y+1});
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (pvv[i][j] && avv[i][j]) v.push_back({i, j});
            }

        return v;
    }
};
