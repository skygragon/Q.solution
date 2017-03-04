/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram
 *
 * Easy (45.27%)
 * Total Accepted:    140357
 * Total Submissions: 309996
 * Testcase Example:  '""\n""'
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s. 
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 */
class Solution {
public:
    int remove_char(string &s, char c) {
        auto f = [&c](char x) { return x == c; };
        auto it = remove_if(s.begin(), s.end(), f);
        int n = distance(it, s.end());
        s.erase(it, s.end());
        return n;
    }

    bool isAnagram(string s, string t) {
        while (true) {
            if (s.empty() && t.empty()) return true;
            if (s.empty() || t.empty()) return false;

            char c = s[0];
            if (remove_char(s, c) != remove_char(t, c)) return false;
        }

        return false;
    }
};
