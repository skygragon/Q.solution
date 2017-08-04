/*
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i
 *
 * algorithms
 * Easy (39.61%)
 * Total Accepted:    7.9K
 * Total Submissions: 20.1K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 
 * Given an array consisting of n integers, find the contiguous subarray of
 * given length k that has the maximum average value. And you need to output
 * the maximum average value.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * Note:
 * 
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 * 
 * 
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, x = numeric_limits<int>::min();
        for (int i = 0, n = nums.size(); i < n; ++i) {
            sum += nums[i];
            if (i >= k) sum -= nums[i-k];
            if (i >= k-1) x = max(x, sum);
        }
        return (double)x / k;
    }
};
