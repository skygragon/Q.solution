/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string
 *
 * Easy (45.91%)
 * Total Accepted:    47249
 * Total Submissions: 102890
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            auto it = m.find(s[i]);
            if (it == m.end()) {
                m[s[i]] = i;
            } else {
                s[it->second] = s[i] += 'A' - 'a';
            }
        }

        for (int i = 0; i < s.size(); ++i)
            if (s[i] >= 'a' && s[i] <= 'z') return i;

        return -1;
    }
};
