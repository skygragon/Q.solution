/*
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one
 *
 * Hard (27.73%)
 * Total Accepted:    27552
 * Total Submissions: 99274
 * Testcase Example:  '-1'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * 
 * For example: 
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12,
 * 13.
 * 
 * 
 * 
 * ⁠ Beware of overflow.
 * 
 */
class Solution {
public:
    int countDigitOne(int n) {
        int m = 0, k = 0, x = 0, base = 1;
        while (n > 0) {
            k = n % 10;
            n = n / 10;

            if (k > 1) { x += (n+1)*base; }
            else if (k < 1) { x += n*base; }
            else { x += n*base+m+1; }

            m += k*base;
            base *= 10;
        }
        return x;
    }
};
