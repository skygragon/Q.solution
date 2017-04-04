/*
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses
 *
 * Hard (34.92%)
 * Total Accepted:    36158
 * Total Submissions: 103486
 * Testcase Example:  '"()())()"'
 *
 * 
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and
 * ). 
 * 
 * 
 * 
 * Examples:
 * 
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 * 
 * 
 * 
 * Credits:Special thanks to @hpplayer for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    string mirror(const string &s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        for (auto &c : s1) { if (c == '(') c = ')'; else if (c == ')') c = '('; }
        return s1;
    }

    void next(unordered_set<string> &ss, const string &s) {
        vector<int> r;
        int k = 0;
        for (int i = 0; i < s.size() && k >= 0; ++i) {
            if (s[i] == '(') ++k;
            if (s[i] == ')') { --k; r.push_back(i); }
        }

        if (k >= 0) {
            ss.insert(mirror(s));
        } else {
            for (auto j : r) next(ss, string(s).erase(j, 1));
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ss1, ss2;
        next(ss1, s);
        for (auto s : ss1) next(ss2, s);
        return vector<string>(ss2.begin(), ss2.end());
    }
};
