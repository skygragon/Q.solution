/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break
 *
 * Medium (28.78%)
 * Total Accepted:    133724
 * Total Submissions: 463910
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words. You may assume the dictionary does
 * not contain duplicate words.
 * 
 * 
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * 
 * 
 * Return true because "leetcode" can be segmented as "leet code".
 * 
 * 
 * 
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
    unordered_map<string, bool> cache;
    vector<string> words;

    bool next(const string& s) {
        if (s.empty()) return true;
        if (cache.find(s) != cache.end()) return cache[s];

        int n = s.size();
        bool found = false;
        for (auto &w : words) {
            int m = w.size();
            if (m > n) continue;
            if (s.compare(0, m, w, 0, m) != 0) continue;

            found = next(s.substr(m));
            if (found) break;
        }
        return cache[s] = found;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        words = wordDict;
        return next(s);
    }
};
