/*
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (32.65%)
 * Total Accepted:    18.1K
 * Total Submissions: 55.3K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(const string &s, int i, int j) {
        while (i < j && s[i] == s[j]) { ++i; --j; }
        return i >= j;
    }

    bool validPalindrome(string s) {
        int n = s.size(), i = 0, j = n - 1;
        while (i < j && s[i] == s[j]) { ++i; --j; }
        if (i >= j) return true;
        return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
    }
};
