/*
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit
 *
 * Easy (30.06%)
 * Total Accepted:    17013
 * Total Submissions: 56486
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
class Solution {
public:
    int findNthDigit(int n) {
        --n;    // ease calculating

        long long len = 1, base = 9;
        while (n >= base * len) {
            n -= base * len;
            ++len;
            base *= 10;
        }

        long long num = n / len + base / 9;
        int x = n % len;
        while (++x < len) num /= 10;
        return num % 10;
    }
};
