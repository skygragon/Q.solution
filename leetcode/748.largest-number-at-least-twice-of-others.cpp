/*
 * [748] Largest Number At Least Twice of Others
 *
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (47.18%)
 * Total Accepted:    4.8K
 * Total Submissions: 10.1K
 * Testcase Example:  '[0,0,0,1]'
 *
 * 
 * In a given integer array nums, there is always exactly one largest element.
 * 
 * Find whether the largest element in the array is at least twice as much as
 * every other number in the array.
 * 
 * If it is, return the index of the largest element, otherwise return -1.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the
 * array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return
 * 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return
 * -1.
 * 
 * 
 * 
 * Note:
 * 
 * nums will have a length in the range [1, 50].
 * Every nums[i] will be an integer in the range [0, 99].
 * 
 * 
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int x = -1, y = -1;
        for (int i = 0; i < nums.size(); ++i) {
          if (x == -1) x = i;
          else if (nums[i] >= nums[x]) { y = x; x = i; }
          else if (y == -1) y = i;
          else if (nums[i] >= nums[y]) y = i;
        }

        return (nums[x] >= nums[y] * 2) ? x : -1;
    }
};
