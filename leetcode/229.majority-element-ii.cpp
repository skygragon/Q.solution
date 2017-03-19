/*
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii
 *
 * Medium (27.99%)
 * Total Accepted:    48729
 * Total Submissions: 174081
 * Testcase Example:  '[]'
 *
 * Given an integer array of size n, find all elements that appear more than
 * &lfloor; n/3 &rfloor; times. The algorithm should run in linear time and in
 * O(1) space.
 * 
 * 
 * ⁠ How many majority elements could it possibly have?
 * ⁠ Do you have a better hint? Suggest it!
 * 
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 0;
        int nx = 0, ny = 0, n = nums.size();

        for (auto num : nums) {
            if (nx > 0 && num == x) ++nx;
            else if (ny > 0 && num == y) ++ny;
            else if (nx == 0) { x = num; ++nx; }
            else if (ny == 0) { y = num; ++ny; }
            else { --nx; --ny; }
        }

        vector<int> v;
        int mx = 0, my = 0;
        for (auto num : nums) {
            if (nx && num == x) ++mx;
            if (ny && num == y) ++my;
        }
        if (mx > n/3) v.push_back(x);
        if (my > n/3) v.push_back(y);
        return v;
    }
};
