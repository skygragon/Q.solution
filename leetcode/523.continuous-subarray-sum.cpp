/*
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum
 *
 * Medium (21.36%)
 * Total Accepted:    4837
 * Total Submissions: 22716
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * 
 * Given a list of non-negative numbers and a target integer k, write a
 * function to check if the array has a continuous subarray of size at least 2
 * that sums up to the multiple of k, that is, sums up to n*k where n is also
 * an integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up
 * to 6.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5
 * and sums up to 42.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit
 * integer.
 * 
 * 
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n);

        for (int i = 0; i < n; ++i) {
            sum[i] = (i > 0 ? sum[i-1] : 0) + nums[i];
            if (i == 0) continue;

            if (k == 0 && sum[i] == 0) return true;
            if (k != 0 && sum[i] % k == 0) return true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int x = sum[i] - sum[j] + nums[j];
                if (k == 0 && x == 0) return true;
                if (k != 0 && x % k == 0) return true;
            }
        }

        return false;
    }
};
