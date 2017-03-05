/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four
 *
 * Easy (37.77%)
 * Total Accepted:    55654
 * Total Submissions: 147278
 * Testcase Example:  '16'
 *
 * 
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 &&
               ((n & (n-1)) == 0) &&
               (n & 0x55555555);
    }
};
