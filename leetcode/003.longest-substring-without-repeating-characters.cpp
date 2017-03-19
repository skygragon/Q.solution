/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 *
 * Medium (23.90%)
 * Total Accepted:    256779
 * Total Submissions: 1074266
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        for (char c = 'a'; c <= 'z'; ++c) m[c] = -1;

        int x = 0, n = s.size(), i = 0, j = 0;
        while (j < n) {
            char c = s[j];
            if (m[c] > -1 && m[c] >= i) i = m[c] + 1;
            m[c] = j++;
            x = max(x, j-i);
        }
        return x;
    }
};
