/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square
 *
 * Medium (27.78%)
 * Total Accepted:    54867
 * Total Submissions: 197477
 * Testcase Example:  '["10100","10111","11111","10010"]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 4.
 * 
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(); if (m == 0) return 0;
        int n = matrix[0].size(); if (n == 0) return 0;
        int x = 0;

        vector<int> h(n, 0), l(n), r(n);
        for (auto &row : matrix) {
            for (int i = 0; i < n; ++i) { l[i] = 0; r[i] = n-1; }
            for (int i = 0; i < n; ++i) h[i] = (row[i] == '0') ? 0 : h[i]+1;

            stack<int> s;
            for (int i = 0; i < n; ++i) {
                while (!s.empty() && h[s.top()] > h[i]) {
                    int j = s.top(); s.pop();
                    r[j] = i-1;
                }
                if (!s.empty()) l[i] = s.top()+1;
                s.push(i);
            }

            for (int i = 0; i < n; ++i) {
                if (h[i] && r[i]-l[i]+1 >= h[i]) x = max(x, h[i]*h[i]);
            }
        }

        return x;
    }
};
