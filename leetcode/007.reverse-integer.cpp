/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer
 *
 * Easy (23.82%)
 * Total Accepted:    215102
 * Total Submissions: 903015
 * Testcase Example:  '0'
 *
 * Reverse digits of an integer.
 * 
 * 
 * Example1: x =  123, return  321
 * Example2: x = -123, return -321
 * 
 * 
 * click to show spoilers.
 * 
 * Have you thought about this?
 * 
 * Here are some good questions to ask before coding. Bonus points for you if
 * you have already thought through this!
 * 
 * If the integer's last digit is 0, what should the output be? ie, cases such
 * as 10, 100.
 * 
 * Did you notice that the reversed integer might overflow? Assume the input is
 * a 32-bit integer, then the reverse of 1000000003 overflows. How should you
 * handle such cases?
 * 
 * For the purpose of this problem, assume that your function returns 0 when
 * the reversed integer overflows.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should
 * return 0 when the reversed integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        if (x == numeric_limits<int>::min()) return 0;

        int n = x > 0 ? x : -x;
        int s = 0, last = 0;
        while (n) {
            s = s * 10 + n % 10;
            n /= 10;
            if (s/10 < last) return 0;
            last = s;
        }

        return x > 0 ? s : -s;
    }
};
