/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
 *
 * Medium (38.98%)
 * Total Accepted:    135727
 * Total Submissions: 348243
 * Testcase Example:  '[1]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int m = i+(j-i)/2;

            if (nums[i] < nums[j]) return nums[i];
            else if (nums[m] > nums[i]) i = m+1;
            else if (nums[m] < nums[j]) j = m;
            else return nums[j];
        }

        return nums[i];
    }
};
