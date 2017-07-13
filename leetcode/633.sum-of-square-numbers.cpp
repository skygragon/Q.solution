/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers
 *
 * Easy (31.10%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '5'
 *
 * 
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = int(sqrt(c));
        while (i <= j) {
            int s = i*i + j*j;
            if (s == c) return true;
            if (s > c) --j; else ++i;
        }
        return false;
    }
};
