/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number
 *
 * Easy (53.24%)
 * Total Accepted:    196475
 * Total Submissions: 369019
 * Testcase Example:  '[1]'
 *
 * Given an array of integers, every element appears twice except for one. Find
 * that single one.
 * 
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto num : nums) x ^= num;
        return x;
    }
};
