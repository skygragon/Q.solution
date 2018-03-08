/*
 * [778] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (35.41%)
 * Total Accepted:    3.9K
 * Total Submissions: 11.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 * 
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "aab"
 * Output: "aba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "aaab"
 * Output: ""
 * 
 * 
 * Note:
 * 
 * 
 * S will consist of lowercase letters and have length in range [1, 500].
 * 
 * 
 * 
 */
class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> m;
        for (auto c: S) ++m[c];

        multimap<int, char, greater<int>> m2;
        for (auto p: m) m2.insert({p.second, p.first});

        int n = S.size(), k = m2.begin()->first;
        if (2 * k - n > 1) return "";
        
        int i = 0;
        vector<string> v(k);
        for (auto p: m2) {
            for (int j = 0; j < p.first; ++j)
                v[(i++) % k].append(1, p.second);
        }

        string res;
        for (auto s: v) res.append(s);
        return res;
    }
};
