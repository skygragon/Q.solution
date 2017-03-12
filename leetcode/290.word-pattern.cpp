/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern
 *
 * Easy (32.37%)
 * Total Accepted:    69199
 * Total Submissions: 213682
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Examples:
 * 
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * 
 * 
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 * 
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    vector<string> split(const string &s, char c) {
        vector<string> v;
        int x = -1, y;
        while (true) {
            y = s.find(c, x+1);
            if (y == string::npos) {
                v.push_back(s.substr(x+1));
                break;
            } else
                v.push_back(s.substr(x+1, y-x-1));
            x = y;
        }
        return v;
    }

    bool wordPattern(string pattern, string str) {
        vector<string> strs = split(str, ' ');

        if (pattern.size() != strs.size()) return false;
        if (pattern.empty()) return true;

        unordered_map<string, string> p2s, s2p;
        for (int i = 0; i < strs.size(); ++i) {
            const string &p = pattern.substr(i, 1);
            const string &s = strs[i];

            auto it1 = p2s.find(p);
            auto it2 = s2p.find(s);
            if (it1 == p2s.end() && it2 == s2p.end()) {
                p2s[p] = s; s2p[s] = p;
                continue;
            }

            if (it1 != p2s.end() && it2 != s2p.end()) {
                if (it1->second != s) return false;
                if (it2->second != p) return false;
                continue;
            }

            return false;
        }

        return true;
    }
};
