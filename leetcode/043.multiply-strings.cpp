/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings
 *
 * Medium (26.24%)
 * Total Accepted:    92082
 * Total Submissions: 350938
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n1 = num1.size(), n2 = num2.size();
        string s(n1+n2, '0');

        for (int i = 0; i < n1; ++i) {
            int x = 0;
            for (int j = 0; j < n2; ++j) {
                x += (num1[i]-'0')*(num2[j]-'0');
                x += s[i+j]-'0';
                s[i+j] = '0'+ x%10;
                x /= 10;
            }

            int j = i + n2;
            while (x) {
                x += s[j]-'0';
                s[j++] = '0' + x % 10;
                x /= 10;
            }
        }

        int i = s.size()-1;
        while (i > 0 && s[i] == '0') --i;
        s.erase(i+1);

        reverse(s.begin(), s.end());
        return s;
    }
};
