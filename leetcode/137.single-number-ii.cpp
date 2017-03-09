/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii
 *
 * Medium (40.48%)
 * Total Accepted:    109332
 * Total Submissions: 270102
 * Testcase Example:  '[1]'
 *
 * 
 * Given an array of integers, every element appears three times except for
 * one, which appears exactly once. Find that single one.
 * 
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
        for (int i = 0; i < sizeof(int)*8; ++i) {
            int mask = (1 << i);

            int s = 0;
            for (auto num : nums) {
                s += ((num & mask) >> i);
            }

            x |= ((s % 3) << i);
        }
        return x;
    }
};
