/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number
 *
 * Easy (34.26%)
 * Total Accepted:    188164
 * Total Submissions: 549236
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int cur = 0, last = 0, n = x;
        while (n) {
            last = cur;
            cur = cur * 10 + n % 10;
            if (cur < last) return false;
            n /= 10;
        }
        return cur == x;
    }
};
