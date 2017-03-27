/*
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive
 *
 * Hard (25.12%)
 * Total Accepted:    91718
 * Total Submissions: 364704
 * Testcase Example:  '[]'
 *
 * 
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * 
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == i+1) continue;
            if (nums[i] <= 0) continue;
            while (nums[i] > 0 && nums[i] <= n) {
                int j = nums[i]-1;
                if (nums[j] == j+1) break;
                swap(nums[i], nums[j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
