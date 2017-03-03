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
        if (tokens.empty()) return 0;

        stack<int> nums;
        stack<string> ops;
        const string OP = "+-*/";

        for (int i = 0; i < tokens.size(); ++i) {
            auto pos = OP.find(tokens[i]);
            if (pos == string::npos) {
                nums.push(stoi(tokens[i]));
            } else {
                int y = nums.top(); nums.pop();
                int x = nums.top(); nums.pop();
                switch(pos) {
                    case 0: nums.push(x + y); break;
                    case 1: nums.push(x - y); break;
                    case 2: nums.push(x * y); break;
                    case 3: nums.push(x / y); break;
                }
            }
        }

        return nums.top();
    }
};
