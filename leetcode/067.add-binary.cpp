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
        int i = a.size()-1, j = b.size()-1, sum = 0;

        string s;
        while (i >= 0 || j >= 0 || sum > 0) {
            if (i >= 0) sum += a[i--]-'0';
            if (j >= 0) sum += b[j--]-'0';

            s = to_string(sum%2) + s;
            sum /= 2;
        }
        return s;
    }
};
