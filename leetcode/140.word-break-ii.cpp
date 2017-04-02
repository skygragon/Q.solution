/*
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii
 *
 * Hard (22.49%)
 * Total Accepted:    80894
 * Total Submissions: 359628
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. You may assume the dictionary does not contain
 * duplicate words.
 * 
 * 
 * 
 * Return all such possible sentences.
 * 
 * 
 * 
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * 
 * 
 * 
 * A solution is ["cats and dog", "cat sand dog"].
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
    unordered_set<string> dict;
    unordered_map<string, vector<string>> cache;

    vector<string> next(const string &s) {
        if (cache.find(s) != cache.end()) return cache[s];
        vector<string> v;
        if (s.empty()) v.push_back("");

        for (int i = 1, n = s.size(); i <= n; ++i) {
            string word = s.substr(0, i);
            if (dict.find(word) == dict.end()) continue;

            vector<string> v1 = next(s.substr(i));
            for (auto &s1 : v1) v.push_back(word + (s1.empty() ? "" : " ") + s1);
        }
        return cache[s] = v;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &word : wordDict) dict.insert(word);
        return next(s);
    }
};
