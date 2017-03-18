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
        int i = 0, j = -1, n = nums.size();
        while (i < n) {
            if (i == 0 || nums[i] != nums[j])
                nums[++j] = nums[i];
            else if (nums[i] == nums[j] && (j == 0 || nums[j] != nums[j-1]))
                nums[++j] = nums[i];
            ++i;
        }
        return j+1;
    }
};
