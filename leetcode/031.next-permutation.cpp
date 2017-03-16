/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation
 *
 * Medium (28.39%)
 * Total Accepted:    100754
 * Total Submissions: 354833
 * Testcase Example:  '[1]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-1;
        while (i > 0 && nums[i] <= nums[i-1]) --i;

        if (i > 0) {
            int j = n-1;
            while (j >= i && nums[j] <= nums[i-1]) --j;
            swap(nums[i-1], nums[j]);
        }

        for (int j = i, k = n-1; j < k; ++j, --k) swap(nums[j], nums[k]);
    }
};
