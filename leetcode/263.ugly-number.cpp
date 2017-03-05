/*
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number
 *
 * Easy (38.59%)
 * Total Accepted:    91656
 * Total Submissions: 237517
 * Testcase Example:  '-2147483648'
 *
 * 
 * Write a program to check whether a given number is an ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another
 * prime factor 7.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};
