/*
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter
 *
 * Easy (56.28%)
 * Total Accepted:    27768
 * Total Submissions: 49293
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water. Grid cells are connected
 * horizontally/vertically (not diagonally). The grid is completely surrounded
 * by water, and there is exactly one island (i.e., one or more connected land
 * cells). The island doesn't have "lakes" (water inside that isn't connected
 * to the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 * 
 * Example:
 * 
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 * 
 * 
 * 
 */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(); if (m == 0) return 0;
        int n = grid[0].size(); if (n == 0) return 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;

                stack<pair<int, int>> s;
                s.push({i,j});

                int k = 0;
                while (!s.empty()) {
                    auto p = s.top(); s.pop();
                    int x = p.first, y = p.second;

                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                        ++k; continue;
                    }
                    if (grid[x][y] == -1) continue;

                    grid[x][y] = -1;
                    s.push({x-1, y});
                    s.push({x+1, y});
                    s.push({x, y-1});
                    s.push({x, y+1});
                }

                return k;
            }

        return 0;
    }
};
