/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum
 *
 * Medium (21.26%)
 * Total Accepted:    190370
 * Total Submissions: 895644
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vv;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            // skip duplicate numbers
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int x = -nums[i], j = i+1, k = n-1;
            while (j < k) {
                int s = nums[j] + nums[k];
                if (s == x) vv.push_back({nums[i], nums[j], nums[k]});

                // skip duplicate numbers
                if (s > x) {
                    while (j < k && nums[k] == nums[k-1]) --k;
                    --k;
                } else {
                    while (j < k && nums[j] == nums[j+1]) ++j;
                    ++j;
                }
            }
        }

        return vv;
    }
};
