/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii
 *
 * Medium (33.33%)
 * Total Accepted:    49614
 * Total Submissions: 148870
 * Testcase Example:  '[]'
 *
 * Note: This is an extension of House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself a new
 * place for his thievery so that he will not get too much attention. This
 * time, all houses at this place are arranged in a circle. That means the
 * first house is the neighbor of the last one. Meanwhile, the security system
 * for these houses remain the same as for those in the previous street. 
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int find(vector<int> &nums, int n) {
        int x = 0;
        vector<int> v(n, 0);

        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < i-1; ++j) cur = max(cur, v[j]);
            v[i] = cur + nums[i];
            x = max(x, v[i]);
        }
        return x;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int x = find(nums, n-1);
        nums[0] = 0;
        x = max(x, find(nums, n));

        return x;
    }
};
