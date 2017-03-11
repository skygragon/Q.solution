/*
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string
 *
 * Easy (33.42%)
 * Total Accepted:    21711
 * Total Submissions: 64933
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;

        int n = s.size(), n1 = p.size();
        if (n == 0 || n1 == 0 || n < n1) return v;

        unordered_map<char, int> m, m1;
        for (auto c : p) ++m[c];

        for (int i = 0; i < n1; ++i) ++m1[s[i]];
        if (m == m1) v.push_back(0);

        for (int i = 1; i <= n-n1; ++i) {
            if (--m1[s[i-1]] == 0) m1.erase(s[i-1]);
            ++m1[s[i+n1-1]];
            if (m == m1) v.push_back(i);
        }

        return v;
    }
};
