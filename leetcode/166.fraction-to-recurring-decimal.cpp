/*
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal
 *
 * Medium (16.99%)
 * Total Accepted:    46726
 * Total Submissions: 275143
 * Testcase Example:  '1\n5'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * For example,
 * 
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * 
 * 
 * 
 * 
 * ⁠ No scary math, just apply elementary math knowledge. Still remember how to
 * perform a long division?
 * ⁠ Try a long division on 4/9, the repeating part is obvious. Now try 4/333.
 * Do you see a pattern?
 * ⁠ Be wary of edge cases! List out as many test cases as you can think of and
 * test your code thoroughly.
 * 
 * 
 * Credits:Special thanks to @Shangrila for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string s;
        if ((numerator < 0 && denominator > 0)) s += "-";
        if ((numerator > 0 && denominator < 0)) s += "-";

        long long x = abs(numerator), y = abs(denominator);
        if (numerator == -2147483648) x = 2147483648LL;
        if (denominator == -2147483648) y = 2147483648LL;

        s += to_string(x / y);
        x = x % y;
        if (x == 0) return s;

        s += '.';

        vector<long long> vx;
        string s1;
        while (x) {
            vx.push_back(x);
            x = x * 10;

            int z = x / y;
            s1 += '0'+z;

            x = x % y;
            for (int i = 0; i < vx.size(); ++i) {
                if (vx[i] == x) {
                    s += s1.substr(0, i);
                    s += "(" + s1.substr(i) + ")";
                    return s;
                }
            }
        }
        return s + s1;
    }
};
