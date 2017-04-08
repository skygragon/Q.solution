/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum
 *
 * Medium (25.95%)
 * Total Accepted:    106405
 * Total Submissions: 409946
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * 
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vv;
        sort(nums.begin(), nums.end());

        for (int i = 0, n = nums.size(); i < n-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i+1; j < n-2; ++j) {
                int sum = nums[i]+nums[j];
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                if (sum+nums[j+1]+nums[j+2] > target) break;
                if (sum+nums[n-2]+nums[n-1] < target) continue;

                int l = j+1, r = n-1;
                while (l < r) {
                    if (sum+nums[l]+nums[r] > target) --r;
                    else if (sum+nums[l]+nums[r] < target) ++l;
                    else { vv.push_back({nums[i], nums[j], nums[l], nums[r]}); ++l; }

                    while (l < r && l > j+1 && nums[l] == nums[l-1]) ++l;
                    while (l < r && r < n-1 && nums[r] == nums[r+1]) --r;
                }
            }
        }
        return vv;
    }
};
