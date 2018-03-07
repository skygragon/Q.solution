/*
 * [800] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (52.49%)
 * Total Accepted:    4.7K
 * Total Submissions: 9K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 * 
 * 
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 * 
 * Input: S = "12345"
 * Output: ["12345"]
 * 
 * 
 * Note:
 * 
 * 
 * S will be a string with length at most 12.
 * S will consist only of letters or digits.
 * 
 */
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> v = {S};
        for (int i = 0, n = S.size(); i < n; ++i) {
            if (S[i] >= '0' && S[i] <= '9') continue;

            vector<string> tmp;
            for (auto &s: v) {
                tmp.push_back(s);
                if (s[i] >= 'a' && s[i] <= 'z')
                    s[i] += 'A' - 'a';
                else
                    s[i] += 'a' - 'A';
                tmp.push_back(s);
            }
            v.swap(tmp);
        }
        return v;
    }
};
