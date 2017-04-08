/*
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 *
 * Medium (35.15%)
 * Total Accepted:    106774
 * Total Submissions: 303745
 * Testcase Example:  '[]'
 *
 * 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * 
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * 
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new
 * length.
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int i = 0;
        for  (int j = 1; j < n; ++j) {
            if (nums[j] != nums[i])
                nums[++i] = nums[j];
            else if (i == 0 || nums[j] != nums[i-1])
                nums[++i] = nums[j];
        }
        return i+1;
    }
};
