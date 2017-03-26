/*
 * [524] Longest Word in Dictionary through Deleting
 *
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
 *
 * Medium (40.16%)
 * Total Accepted:    4118
 * Total Submissions: 10232
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * Given a string and a string dictionary, find the longest string in the
 * dictionary that can be formed by deleting some characters of the given
 * string. If there are more than one possible results, return the longest word
 * with the smallest lexicographical order. If there is no possible result,
 * return the empty string.
 * 
 * Example 1:
 * 
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * Output: 
 * "apple"
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * Output: 
 * "a"
 * 
 * 
 * 
 * Note:
 * 
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
 * 
 * 
 */
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        auto comp = [](const string &s1, const string &s2) {
            return s1.size() > s2.size() ||
                   (s1.size() == s2.size() && s1 < s2);
        };
        sort(d.begin(), d.end(), comp);

        for (auto &word : d) {
            int i = 0, j = 0, n = word.size(), m = s.size();
            while (i < n && j < m) {
                while (j < m && s[j] != word[i]) ++j;
                if (j == m) break;
                ++i; ++j;
            }
            if (i == n) return word;
        }
        return "";
    }
};
