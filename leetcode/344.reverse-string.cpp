/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string
 *
 * Easy (57.93%)
 * Total Accepted:    135896
 * Total Submissions: 234506
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * 
 * Example:
 * Given s = "hello", return "olleh".
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.size()-1; i < j; ++i, --j)
            swap(s[i], s[j]);

        return s;
    }
};
