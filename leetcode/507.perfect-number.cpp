/*
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number
 *
 * Easy (29.98%)
 * Total Accepted:    1936
 * Total Submissions: 6458
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself. 
 * 
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * 
 * 
 * Example:
 * 
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 * 
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;

        int s = 1;
        for (int i = 2; i*i <= num; ++i) {
            if (num % i == 0) {
                s += i;
                if (i*i != num) s += num/i;
            }
        }
        return num == s;
    }
};
