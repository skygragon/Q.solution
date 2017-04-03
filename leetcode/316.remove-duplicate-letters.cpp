/*
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters
 *
 * Hard (29.01%)
 * Total Accepted:    27581
 * Total Submissions: 95044
 * Testcase Example:  '"bcabc"'
 *
 * 
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appear once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given "bcabc"
 * Return "abc"
 * 
 * 
 * Given "cbacdcbc"
 * Return "acdb"
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        unordered_map<char, bool> used;
        for (auto c : s) { ++count[c]; used[c] = false; }

        string x;
        for (auto c : s) {
            --count[c];
            if (used[c]) continue;

            while (!x.empty() && c < x.back() && count[x.back()] > 0) {
                used[x.back()] = false; x.pop_back();
            }
            x.push_back(c);
            used[c] = true;
        }
        return x;
    }
};
