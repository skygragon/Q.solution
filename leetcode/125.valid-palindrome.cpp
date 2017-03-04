/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome
 *
 * Easy (25.64%)
 * Total Accepted:    145942
 * Total Submissions: 569134
 * Testcase Example:  '""'
 *
 * 
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * 
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 * 
 */
class Solution {
public:
    int lower(char c) {
        if (c >= '0' && c <= '9') return c;
        if (c >= 'a' && c <= 'z') return c;
        if (c >= 'A' && c <= 'Z') return c-'A'+'a';
        return 0;
    }

    bool isPalindrome(string s) {
        bool b = true;

        int i = 0, j = s.size()-1;
        while (i < j && b) {
            while (!lower(s[i])) ++i;
            if (i >= j) break;

            while (!lower(s[j])) --j;
            if (i >= j) break;

            if (lower(s[i]) != lower(s[j])) b = false;
            ++i; --j;
        }

        return b;
    }
};
