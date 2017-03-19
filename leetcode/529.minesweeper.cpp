/*
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper
 *
 * Medium (52.35%)
 * Total Accepted:    3096
 * Total Submissions: 5939
 * Testcase Example:  '["EEEEE","EEMEE","EEEEE","EEEEE"]\n[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)! 
 * 
 * You are given a 2D char matrix representing the game board. 'M' represents
 * an unrevealed mine, 'E' represents an unrevealed empty square, 'B'
 * represents a revealed blank square that has no adjacent (above, below, left,
 * right, and all 4 diagonals) mines, digit ('1' to '8') represents how many
 * mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 * 
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules: 
 * 
 * 
 * 
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent mines.
 * Return the board when no more squares will be revealed.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The range of the input matrix's height and width is [1,50].
 * The click position will only be an unrevealed square ('M' or 'E'), which
 * also means the input board contains at least one clickable square.
 * The input board won't be a stage when game is over (some mines have been
 * revealed).
 * For simplicity, not mentioned rules should be ignored in this problem. For
 * example, you don't need to reveal all the unrevealed mines when the game is
 * over, consider any cases that you will win the game or flag any squares.
 * 
 * 
 */
class Solution {
public:
    using P = pair<int, int>;

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> &vv = board;
        for (int i = 0, n = click.size(); i < n; i += 2) {
            int x = click[i], y = click[i+1];
            if (vv[x][y] == 'M') { vv[x][y] = 'X'; break; }
            if (vv[x][y] != 'E') continue;

            stack<P> s; s.push({x,y});

            while (!s.empty()) {
                auto p = s.top(); s.pop();
                x = p.first; y = p.second;
                if (vv[x][y] != 'E') continue;

                vector<P> v;
                int mines = 0;
                for (int j = 0; j < 9; ++j) {
                    int x1 = x+j/3-1, y1 =y+j%3-1;

                    if (x == x1 && y == y1) continue;
                    if (x1 < 0 || x1 >= vv.size()) continue;
                    if (y1 < 0 || y1 >= vv[0].size()) continue;

                    if (vv[x1][y1] == 'M') { ++mines; continue; }
                    if (vv[x1][y1] != 'E') continue;

                    v.push_back({x1, y1});
                }

                vv[x][y] = mines ? '0'+mines : 'B';
                if (mines > 0) continue;

                for (auto &p1 : v) s.push(p1);
            }
        }
        return vv;
    }
};
