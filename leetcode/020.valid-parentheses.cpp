/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * Easy (32.56%)
 * Total Accepted:    176847
 * Total Submissions: 543111
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {{')','('}, {']','['}, {'}','{'}};

        stack<char> sc;
        for (auto c : s) {
            switch(c) {
                case '(': case '[': case '{': sc.push(c); break;
                case ')': case ']': case '}': if (sc.empty() || sc.top() != m[c]) return false; sc.pop(); break;
            }
        }
        return sc.empty();
    }
};
