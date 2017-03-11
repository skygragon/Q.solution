/*
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman
 *
 * Medium (43.32%)
 * Total Accepted:    95349
 * Total Submissions: 220086
 * Testcase Example:  '1'
 *
 * Given an integer, convert it to a roman numeral.
 * 
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    string intToRoman(int n) {
        string str;

        vector<string> v = { "M??", "CDM", "XLC", "IVX" };

        int base = 1000, i = 0, k;
        while (n) {
            string &s = v[i];

            if (n >= base*9) {
                k = (10-n/base); str += string(k, s[0]) + string(1, s[2]);
            } else if (n >= base*5) {
                k = (n/base-5); str += string(1, s[1]) + string(k, s[0]);
            } else if (n >= base*4) {
                k = (5-n/base); str += string(k, s[0]) + string(1, s[1]);
            } else {
                k = n/base; str += string(k, s[0]);
            }

            n %= base; base /= 10; ++i;
        }

        return str;
    }
};
