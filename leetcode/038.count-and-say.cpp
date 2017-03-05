/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say
 *
 * Easy (33.10%)
 * Total Accepted:    121564
 * Total Submissions: 367223
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * 
 * 
 * Note: The sequence of integers will be represented as a string.
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        while (--n) {
            ostringstream oss;
            int last = 0, n =s.size();
            for (int i = 1; i <= n; ++i) {
                if (i == n || s[last] != s[i]) {
                    oss << (i-last) << s[last];
                    last = i;
                }
            }
            s = oss.str();
        }

        return s;
    }
};
