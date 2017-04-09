/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation
 *
 * Medium (26.24%)
 * Total Accepted:    86081
 * Total Submissions: 328021
 * Testcase Example:  '["18"]'
 *
 * 
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation.
 * 
 * 
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * 
 * 
 * Some examples:
 * 
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * 
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        const string OPS = "+-*/";
        stack<int> nums;
        for (auto &s : tokens) {
            if (OPS.find(s) == string::npos) {
                nums.push(stoi(s));
            } else {
                int y = nums.top(); nums.pop();
                int x = nums.top(); nums.pop();
                switch(s[0]) {
                    case '+': nums.push(x + y); break;
                    case '-': nums.push(x - y); break;
                    case '*': nums.push(x * y); break;
                    case '/': nums.push(x / y); break;
                }
            }
        }
        return nums.empty() ? 0 : nums.top();
    }
};
