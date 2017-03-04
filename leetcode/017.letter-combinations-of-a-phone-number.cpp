/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number
 *
 * Medium (33.06%)
 * Total Accepted:    131611
 * Total Submissions: 398141
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    unordered_map<char, string> M = {
        {'0', ""},
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    string digits;
    int n;
    string s;
    vector<string> v;

    void next(int i) {
        if (i == n) return v.push_back(s);
        for (auto c : M[digits[i]]) { s[i] = c; next(i+1); }
    }

    vector<string> letterCombinations(string digits) {
        n = digits.size();
        this->digits = digits;
        s.resize(n);

        if (n > 0) next(0);
        return v;
    }
};
