/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome
 *
 * Easy (44.59%)
 * Total Accepted:    29761
 * Total Submissions: 66745
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        int n = 0;

        unordered_map<char, int> m;
        for (auto& c : s) ++m[c];

        bool hasSingle = false;
        for (auto& p : m) {
            n += p.second;
            if (p.second % 2 == 1) {
                --n;
                hasSingle = true;
            }
        }

        return n + (hasSingle ? 1 : 0);
    }
};
