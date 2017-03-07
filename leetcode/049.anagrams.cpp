/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/anagrams
 *
 * Medium (32.66%)
 * Total Accepted:    119713
 * Total Submissions: 366498
 * Testcase Example:  '[""]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& str : strs) {
            string k = str;
            sort(k.begin(), k.end());
            m[k].push_back(str);
        }

        vector<vector<string>> vv;
        for (auto& p : m) vv.push_back(p.second);
        return vv;
    }
};
