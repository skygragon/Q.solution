/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings
 *
 * Easy (32.85%)
 * Total Accepted:    94078
 * Total Submissions: 286382
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * For example,
 * Given "egg", "add", return true.
 * 
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        if (s.empty()) return true;

        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s.size(); ++i) {
            auto it = m1.find(s[i]);
            if (it == m1.end()) {
                if (m2.find(t[i]) != m2.end()) return false;
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else {
                if (it->second != t[i]) return false;
            }
        }
        return true;
    }
};
