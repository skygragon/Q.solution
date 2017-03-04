/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three
 *
 * Easy (39.58%)
 * Total Accepted:    84691
 * Total Submissions: 213970
 * Testcase Example:  '27'
 *
 * 
 * Given an integer, write a function to determine if it is a power of
 * three.
 * 
 * 
 * Follow up:
 * Could you do it without using any loop / recursion?
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};
