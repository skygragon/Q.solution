/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array
 *
 * Medium (32.10%)
 * Total Accepted:    151449
 * Total Submissions: 471860
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int m = i+(j-i)/2;
            if (nums[m] == target) return m;
            if (nums[i] == target) return i;
            if (nums[j] == target) return j;

            if (nums[m] > target) {
                if (nums[i] < target || nums[i] > nums[m]) j = m-1;
                else i = m+1;
            } else {
                if (nums[i] < nums[m] || nums[i] > target) i = m+1;
                else j = m-1;
            }
        }
        return -1;
    }
};
