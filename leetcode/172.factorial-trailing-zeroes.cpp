/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes
 *
 * Easy (35.16%)
 * Total Accepted:    84636
 * Total Submissions: 240719
 * Testcase Example:  '0'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int x = 0;

        while (n) {
            n = n / 5;
            x += n;
        }

        return x;
    }
};
