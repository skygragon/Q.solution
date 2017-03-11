/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self
 *
 * Medium (47.71%)
 * Total Accepted:    85606
 * Total Submissions: 179404
 * Testcase Example:  '[0,0]'
 *
 * 
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Solve it without division and in O(n).
 * 
 * For example, given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n), v(n);

        for (int i = 0, x = 1; i < n; ++i) left[i] = x *= nums[i];
        for (int i = n-1, x = 1; i >= 0; --i) right[i] = x *= nums[i];

        for (int i = 0; i < n; ++i) {
            int x = 1;
            if (i > 0) x *= left[i-1];
            if (i < n-1) x *= right[i+1];
            v[i] = x;
        }

        return v;
    }
};
