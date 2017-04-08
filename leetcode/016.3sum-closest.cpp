/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest
 *
 * Medium (30.67%)
 * Total Accepted:    115429
 * Total Submissions: 376351
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int NA = numeric_limits<int>::min(), res = NA;
        for (int k = 0, n = nums.size(); k < n; ++k) {
            int i = k+1, j = n-1;

            while (i < j) {
                int sum = nums[i]+nums[j]+nums[k];

                if (sum == target) return target;
                if (sum < target) ++i; else --j;
                if (res == NA || abs(res-target) > abs(sum-target)) res = sum;
            }
        }
        return res;
    }
};
