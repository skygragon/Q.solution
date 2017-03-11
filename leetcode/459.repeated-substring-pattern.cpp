/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern
 *
 * Easy (38.67%)
 * Total Accepted:    21979
 * Total Submissions: 56887
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters only
 * and its length  will not exceed 10000. 
 * 
 * Example 1:
 * 
 * Input: "abab"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aba"
 * 
 * Output: False
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "abcabcabcabc"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */
class Solution {
public:
    bool check(string &s, int m) {
        int i = 0, n = s.size();
        while (i < n) {
            if (s.compare(i, m, s, 0, m) != 0) return false;
            i += m;
        }
        return true;
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n < 2) return false;

        for (int i = 1; i <= sqrt(n); ++i) {
            if (n % i) continue;
            if (i > 1 && check(s, n/i)) return true;
            if (check(s, i)) return true;
        }
        return false;
    }
};
