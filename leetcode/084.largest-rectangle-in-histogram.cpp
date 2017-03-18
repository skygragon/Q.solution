/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram
 *
 * Hard (25.89%)
 * Total Accepted:    82818
 * Total Submissions: 319865
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> L(n, 0), R(n, n-1);

        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int x = s.top(); s.pop(); R[x] = i-1;
            }

            if (!s.empty()) L[i] = s.top()+1;
            s.push(i);
        }

        while (!s.empty()) {
            int x = s.top(); s.pop();
            if (!s.empty()) L[x] = s.top()+1;
        }

        int x = 0;
        for (int i = 0; i < n; ++i)
            x = max(x, (R[i]-L[i]+1)*heights[i]);
        return x;
    }
};
