/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string
 *
 * Easy (37.03%)
 * Total Accepted:    13855
 * Total Submissions: 37412
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int countSegments(string s) {
        int x = 0, last = -1, n = s.size();
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (i-last-1 > 0) ++x;
                last = i;
            }
        }

        return x;
    }
};
