/*
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses
 *
 * Medium (42.24%)
 * Total Accepted:    39928
 * Total Submissions: 94494
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1
 * Input: "2-1-1". 
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * Example 2
 * Input: "2*3-4*5" 
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10] 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        for (int i = 0, n = input.size(), last = -1; i <= n; ++i) {
            if (i < n && input[i] <= '9' && input[i] >= '0') continue;
            if (i < n) ops.push_back(input[i]);
            nums.push_back(stoi(input.substr(last+1, i-last-1)));
            last = i;
        }

        int n = nums.size();
        if (n == 0) return {};

        vector<vector<vector<int>>> vvv(n);
        for (auto &vv: vvv) vv.resize(n);
        for (int i = 0; i < n; ++i) vvv[i][i] = { nums[i] };

        for (int i = 1; i < n; ++i)
            for (int j = i-1; j >= 0; --j)
                for (int k = j; k < i; ++k)
                    for (auto x : vvv[j][k])
                        for (auto y : vvv[k+1][i]) {
                            switch (ops[k]) {
                                case '+': vvv[j][i].push_back(x+y); break;
                                case '-': vvv[j][i].push_back(x-y); break;
                                case '*': vvv[j][i].push_back(x*y); break;
                            }
                        }

        return vvv[0][n-1];
    }
};
