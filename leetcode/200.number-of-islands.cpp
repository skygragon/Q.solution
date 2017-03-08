/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands
 *
 * Medium (33.02%)
 * Total Accepted:    92564
 * Total Submissions: 280188
 * Testcase Example:  '["11110","11010","11000","00000"]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int k = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;

                queue<pair<int, int>> q;
                q.push({i,j}); grid[i][j] = '0';
                ++k;

                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();

                    int x = p.first, y = p.second;
                    grid[x][y] = '0';

                    if (x > 0 && grid[x-1][y] == '1') {
                        grid[x-1][y] = '0'; q.push({x-1, y});
                    }
                    if (x < m-1 && grid[x+1][y] == '1') {
                        grid[x+1][y] = '0'; q.push({x+1, y});
                    }
                    if (y > 0 && grid[x][y-1] == '1') {
                        grid[x][y-1] = '0'; q.push({x, y-1});
                    }
                    if (y < n-1 && grid[x][y+1] == '1') {
                        grid[x][y+1] = '0'; q.push({x, y+1});
                    }
                }
            }

        return k;
    }
};
