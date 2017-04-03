/*
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons
 *
 * Hard (41.99%)
 * Total Accepted:    23743
 * Total Submissions: 56499
 * Testcase Example:  '[3,1,5,8]'
 *
 * 
 * ⁠   Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * ⁠   number on it represented by array nums.
 * 
 * ⁠   You are asked to burst all the balloons. If the you burst
 * ⁠   balloon i you will get nums[left] * nums[i] * nums[right] coins. Here
 * left
 * ⁠   and right are adjacent indices of i. After the burst, the left and right
 * ⁠   then becomes adjacent.
 * 
 * 
 * ⁠   Find the maximum coins you can collect by bursting the balloons
 * wisely.
 * 
 * 
 * ⁠   Note: 
 * ⁠   (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore
 * you can not burst them.
 * ⁠   (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * 
 * 
 * ⁠   Example:
 * 
 * 
 * ⁠   Given [3, 1, 5, 8]
 * 
 * 
 * ⁠   Return 167
 * 
 * 
 * ⁠   nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 * ⁠  coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 1; i <= n-2; ++i) dp[i][i] = nums[i-1]*nums[i]*nums[i+1];

        for (int len = 2; len <= n-2; ++len)
            for (int i = 1; i <= n-len-1; ++i) {
                int j = i+len-1;
                for (int k = i; k <= j; ++k) {
                    int x = nums[k]*nums[i-1]*nums[j+1];
                    if (i<=k-1) x += dp[i][k-1];
                    if (j>=k+1) x += dp[k+1][j];

                    dp[i][j] = max(dp[i][j], x);
                }
            }

        return dp[1][n-2];
    }
};
