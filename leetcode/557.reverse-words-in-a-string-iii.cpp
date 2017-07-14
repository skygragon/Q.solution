/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii
 *
 * Easy (59.95%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), j = -1;
        for (int i = 0; i <= n; ++i) {
            if (i < n && s[i] != ' ') continue;
            for (int b = j+1, e = i-1; b < e; ++b, --e) swap(s[b], s[e]);
            j = i;
        }
        return s;
    }
};
