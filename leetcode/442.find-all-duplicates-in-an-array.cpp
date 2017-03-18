/*
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array
 *
 * Medium (52.62%)
 * Total Accepted:    20436
 * Total Submissions: 38805
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) nums[nums[i]%n] += n;

        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if ((nums[i]-1)/n == 2) v.push_back(i > 0 ? i : n);
        }
        return v;
    }
};
