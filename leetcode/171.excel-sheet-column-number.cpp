/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number
 *
 * Easy (45.72%)
 * Total Accepted:    119019
 * Total Submissions: 260287
 * Testcase Example:  '"A"'
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * A -&gt; 1
 * B -&gt; 2
 * C -&gt; 3
 * ...
 * Z -&gt; 26
 * AA -&gt; 27
 * AB -&gt; 28 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;
        for (auto c : s) n = n * 26 + c - 'A' + 1;
        return n;
    }
};
