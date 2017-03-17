/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum
 *
 * Medium (29.23%)
 * Total Accepted:    71611
 * Total Submissions: 244965
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * 
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n).
 * 
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = -1, n = nums.size();
        int x = n+1, cur = 0;

        while (j < n && i < n) {
            if (j < 0 || cur < s) {
                cur += nums[++j];
            } else if (cur >= s) {
                x = min(x, j-i+1);
                cur -= nums[i++];
            }
        }

        return x > n ? 0 : x;
    }
};
