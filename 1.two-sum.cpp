/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum
 *
 * Easy (29.13%)
 * Total Accepted:    368339
 * Total Submissions: 1264612
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 * UPDATE (2016/2/13):
 * The return format had been changed to zero-based indices. Please read the
 * above updated description carefully.
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) return {it->second, i};
            m[nums[i]] = i;
        }
        return {};
    }
};






