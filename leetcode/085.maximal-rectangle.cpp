/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle
 *
 * Hard (26.84%)
 * Total Accepted:    61206
 * Total Submissions: 228075
 * Testcase Example:  '["10100","10111","11111","10010"]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
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
 * Return 6.
 * 
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); if (m == 0) return 0;
        int n = matrix[0].size(); if (n == 0) return 0;

        vector<int> h(n, 0), l(n), r(n);
        int x = 0;

        for (auto &row : matrix) {
            for (int i = 0; i < n; ++i) h[i] = (row[i] == '1') ? h[i]+1 : 0;

            stack<int> s;
            for (int i = 0; i < n; ++i) {
                l[i] = r[i] = i;
                while (!s.empty() && h[s.top()] > h[i]) { int j = s.top(); s.pop(); r[j] = i-1; }
                l[i] = (!s.empty()) ? s.top()+1 : 0;
                s.push(i);
            }
            while (!s.empty()) { int j = s.top(); s.pop(); r[j] = n-1; }

            for (int i = 0; i < n; ++i) {
                if (l[i] == -1 || r[i] == -1 || h[i] == 0) continue;
                x = max(x, h[i]*(r[i]-l[i]+1));
            }
        }
        return x;
    }
};
