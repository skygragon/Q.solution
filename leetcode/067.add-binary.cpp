/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary
 *
 * Easy (31.02%)
 * Total Accepted:    128475
 * Total Submissions: 414184
 * Testcase Example:  '"0"\n"0"'
 *
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * 
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int x = 0;

        string s;
        while (i >= 0 || j >= 0 || x > 0) {
            x += (i >= 0) ? a[i] - '0' : 0;
            x += (j >= 0) ? b[j] - '0' : 0;

            s = to_string(x % 2) + s;
            x /= 2; --i; --j;
        }

        return s;
    }
};
