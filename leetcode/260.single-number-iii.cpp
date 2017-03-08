/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii
 *
 * Medium (49.93%)
 * Total Accepted:    60357
 * Total Submissions: 120846
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * 
 * For example:
 * 
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (auto num : nums) s ^= num;
        while (s & (s - 1)) s &= (s-1);

        int x = 0, y = 0;
        for (auto num : nums) {
            if (num & s) x ^= num;
            else y ^= num;
        }

        return {x, y};
    }
};
