/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion
 *
 * Easy (25.75%)
 * Total Accepted:    124284
 * Total Submissions: 482570
 * Testcase Example:  '""\n1'
 *
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string s1;
        int n = s.size();
        int k1 = numRows-1, k2 = 0;

        while (k1 >= 0) {
            int i = k2;
            s1 += s[i];
            while (i < n) {
                if (k1 > 0) {
                    i += k1*2;
                    if (i >= n) break;
                    s1 += s[i];
                }
                if (k2 > 0) {
                    i += k2*2;
                    if (i >= n) break;
                    s1 += s[i];
                }
            }
            --k1; ++k2;
        }

        return s1;
    }
};
