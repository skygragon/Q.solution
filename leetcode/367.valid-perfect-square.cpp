/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square
 *
 * Easy (37.66%)
 * Total Accepted:    33178
 * Total Submissions: 88052
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * 
 * Input: 16
 * Returns: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 14
 * Returns: False
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isPerfectSquare(int n) {
        int i = 1, j = n;
        while (i <= j) {
            int m = i+(j-i)/2;
            int x = n / m;

            if (x == m && (n % m == 0)) return true;
            else if (x < m) j = m-1;
            else i = m+1;
        }
        return false;
    }
};
