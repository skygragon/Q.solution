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
        heights.push_back(0);
        int winner = 0;

        stack<int> s;
        for (int i = 0, n = heights.size(); i < n; ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()]; s.pop();
                int j = s.empty() ? 0 : s.top()+1;
                winner = max(winner, h*(i-j));
            }
            s.push(i);
        }
        return winner;
    }
};
