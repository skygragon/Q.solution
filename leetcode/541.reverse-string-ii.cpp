/*
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii
 *
 * Easy (44.51%)
 * Total Accepted:    4396
 * Total Submissions: 9880
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, n = s.size();
        while (i < n) {
            int j = min(n-1, i+k-1);

            int i1 = i, j1 = j;
            while (i1 < j1) swap(s[i1++], s[j1--]);

            i = j+k+1;
        }
        return s;
    }
};
