/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title
 *
 * Easy (24.90%)
 * Total Accepted:    92476
 * Total Submissions: 371385
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB 
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    const string UPPERS = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string convertToTitle(int n) {
        string s;
        while (n) {
            int m = n % 26;
            s = UPPERS.substr(m, 1) + s;
            n = n/26 - (m == 0 ? 1 : 0);
        }
        return s;
    }
};
