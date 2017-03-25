/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii
 *
 * Medium (32.86%)
 * Total Accepted:    85756
 * Total Submissions: 260960
 * Testcase Example:  '[]\n5'
 *
 * 
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Write a function to determine if a given target is in the array.
 * 
 * The array may contain duplicates.
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int m = i+(j-i)/2;
            if (nums[m] == target) return true;
            if (nums[i] == target) return true;
            if (nums[j] == target) return true;

            if (nums[m] == nums[i]) ++i;
            else if (nums[m] > target) {
                if (nums[i] < target || nums[i] > nums[m]) j = m-1;
                else i = m+1;
            } else {
                if (nums[i] < nums[m] || nums[i] > target) i = m+1;
                else j = m-1;
            }
        }
        return false;
    }
};
