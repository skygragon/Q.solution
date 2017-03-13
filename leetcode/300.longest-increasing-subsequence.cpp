/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence
 *
 * Medium (37.63%)
 * Total Accepted:    67714
 * Total Submissions: 179799
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * 
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length
 * is 4. Note that there may be more than one LIS combination, it is only
 * necessary for you to return the length.
 * 
 * 
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int x = 0, n = nums.size();
        vector<int> v(n, 0);

        for (int i = 0; i < n; ++i) {
            int y = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) y = max(y, v[j]);
            }
            v[i] = y+1;
            x = max(x, v[i]);
        }

        return x;
    }
};
