/*
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii
 *
 * Hard (36.46%)
 * Total Accepted:    71545
 * Total Submissions: 196221
 * Testcase Example:  '[1]'
 *
 * 
 * Follow up for "Find Minimum in Rotated Sorted Array":
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
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1;
        while (i <= j) {
            if (nums[i] < nums[j]) return nums[i];
            else if (nums[i] == nums[j]) ++i;
            else {
                int m = i+(j-i)/2;
                if (nums[m] >= nums[i]) i = m+1;
                else if (nums[m] <= nums[j]) j = m;
            }
        }

        return nums[j];
    }
};
