/*
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones
 *
 * Easy (55.00%)
 * Total Accepted:    22924
 * Total Submissions: 41669
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 * 
 * Example 1:
 * 
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * The maximum number of consecutive 1s is 3.
 * 
 * 
 * 
 * Note:
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 * 
 * 
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int x = 0, last = -1, n = nums.size();
        for (int i = 0; i <= n; ++i) {
            if (i < n && nums[i]) continue;
            x = max(x, i-last-1);
            last = i;
        }
        return x;
    }
};
