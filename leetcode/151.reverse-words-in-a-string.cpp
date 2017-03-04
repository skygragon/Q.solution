/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string
 *
 * Medium (15.73%)
 * Total Accepted:    144505
 * Total Submissions: 918927
 * Testcase Example:  '""'
 *
 * 
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * 
 * 
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 * 
 * 
 * click to show clarification.
 * 
 * Clarification:
 * 
 * 
 * 
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing
 * spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 * 
 * 
 * 
 */
class Solution {
public:
    void reverse(string &s, int i, int j) {
        while (i < j) swap(s[i++], s[j--]);
    }

    void reverseWords(string &s) {
        int last = -1, j = -1, n = s.size();
        for (int i = 0; i <= n; ++i) {
            if (i < n && s[i] != ' ') continue;

            reverse(s, last+1, i-1);
            if (i>last+1) {
                for (int k = last+1; k < i; ++k) s[++j] = s[k];
                if (j<n-1) s[++j] = ' ';
            }
            last = i;
        }

        while (s[j] == ' ') --j;
        s.resize(j+1);
        reverse(s, 0, s.size()-1);
    }
};
