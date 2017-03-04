/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs
 *
 * Easy (38.97%)
 * Total Accepted:    157432
 * Total Submissions: 403940
 * Testcase Example:  '1'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Note: Given n will be a positive integer.
 * 
 */
class Solution {
public:
    int climbStairs(int n) {
        int x = 0, y = 1, z;
        for (int i = 1; i <= n; ++i) { z = x+y; x = y; y = z; }
        return y;
    }
};
