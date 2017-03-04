/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes
 *
 * Easy (48.44%)
 * Total Accepted:    162591
 * Total Submissions: 335661
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * 
 * 
 * For example, given nums  = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 * 
 * 
 * 
 * Note:
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1, j = 0, n = nums.size();
        while (j < n) {
            if (nums[j] != 0) {
                nums[++i] = nums[j];
            }
            ++j;
        }

        ++i;
        while (i < n) nums[i++] = 0;
    }
};
