/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle
 *
 * Medium (32.79%)
 * Total Accepted:    95708
 * Total Submissions: 291854
 * Testcase Example:  '[[-10]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * 
 * For example, given the following triangle
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * 
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;

        vector<int> v(n, triangle[0][0]);
        for (int i = 1; i < n; ++i) {
            v[i] = v[i-1] + triangle[i][i];
            for (int j = i-1; j >= 1; --j) {
                v[j] = min(v[j], v[j-1]) + triangle[i][j];
            }
            v[0] = v[0] + triangle[i][0];
        }
        return *min_element(v.begin(), v.end());
    }
};
