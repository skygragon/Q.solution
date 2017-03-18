/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water
 *
 * Medium (36.19%)
 * Total Accepted:    118578
 * Total Submissions: 327610
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), x = 0;
        for (int k = 0; k < n; ++k) {
            int i = 0, j = n-1;

            while (i < k && height[i] < height[k]) ++i;
            x = max(x, height[k]*(k-i));

            while (j > k && height[j] < height[k]) --j;
            x = max(x, height[k]*(j-k));
        }
        return x;
    }
};
