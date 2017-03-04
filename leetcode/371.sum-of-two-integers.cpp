/*
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers
 *
 * Easy (51.20%)
 * Total Accepted:    58664
 * Total Submissions: 114604
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * Example:
 * Given a = 1 and b = 2, return 3.
 * 
 * 
 * Credits:Special thanks to @fujiaozhu for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int x = a ^ b;
            int y = (a & b) << 1;
            a = x; b = y;
        }
        return a;
    }
};
