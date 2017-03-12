/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber
 *
 * Easy (37.80%)
 * Total Accepted:    119416
 * Total Submissions: 315879
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> v(n);
        int x = 0;

        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < i-1; ++j) {
                cur = max(cur, v[j]);
            }
            v[i] = cur + nums[i];
            x = max(x, v[i]);
        }

        return x;
    }
};
