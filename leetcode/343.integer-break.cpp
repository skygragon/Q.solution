/*
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break
 *
 * Medium (45.23%)
 * Total Accepted:    37696
 * Total Submissions: 83324
 * Testcase Example:  '2'
 *
 * 
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * 
 * 
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10
 * = 3 + 3 + 4).
 * 
 * 
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 * 
 * ⁠ There is a simple O(n) solution to this problem.
 * ⁠ You may check the breaking results of n ranging from 7 to 10 to discover
 * the regularities.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int integerBreak(int n) {
        if (n < 3) return 1;
        if (n == 3) return 2;

        int x = pow(3, n/3-1);

        switch (n % 3) {
            case 0: x = x*3; break;
            case 1: x = x*4; break;
            case 2: x = x*3*2; break;
        }
        return x;
    }
};
