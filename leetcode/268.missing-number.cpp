/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number
 *
 * Easy (43.84%)
 * Total Accepted:    97117
 * Total Submissions: 221548
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * 
 * For example,
 * Given nums = [0, 1, 3] return 2.
 * 
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = (n + 1) * n / 2;
        for (auto num : nums) x -= num;
        return x;
    }
};
