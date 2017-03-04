/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings
 *
 * Easy (41.24%)
 * Total Accepted:    25104
 * Total Submissions: 60869
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string s;
        int i = num1.size() -1;
        int j = num2.size() -1;
        int x = 0;
        while (i >=0 || j >= 0 || x > 0) {
            if (i >= 0) x += num1[i--] - '0';
            if (j >= 0) x += num2[j--] - '0';
            s = to_string(x % 10) + s;
            x /= 10;
        }
        return s;
    }
};
