/*
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii
 *
 * Medium (28.51%)
 * Total Accepted:    41772
 * Total Submissions: 146563
 * Testcase Example:  '"0"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 * 
 * 
 * 
 * 
 * Note: Do not use the eval built-in library function.
 * 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    const string OPS = "+-*/";

    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;

        int x = 0;
        for (int i = 0, n = s.size(); i <= n; ++i) {
            if (i == n) {
                nums.push_back(x);
            } else {
                char c = s[i];
                if (c == ' ') {
                    continue;
                } else if (OPS.find(s[i]) != string::npos) {
                    ops.push_back(c);
                    nums.push_back(x);
                    x = 0;
                } else {
                    x = x*10+c-'0';
                }
            }
        }

        int i = 0, n = ops.size();
        while (i < n) {
            bool skip = false;
            switch (ops[i]) {
                case '*': nums[i] = nums[i] * nums[i+1]; break;
                case '/': nums[i] = nums[i] / nums[i+1]; break;
                default: skip = true; break;
            }
            if (skip) ++i;
            else { nums.erase(nums.begin()+i+1); ops.erase(ops.begin()+i); --n; }
        }

        i = 0;
        while (i < n) {
            switch (ops[i]) {
                case '+': nums[i] = nums[i] + nums[i+1]; break;
                case '-': nums[i] = nums[i] - nums[i+1]; break;
            }
            nums.erase(nums.begin()+i+1); ops.erase(ops.begin()+i); --n;
        }

        return nums[0];
    }
};
