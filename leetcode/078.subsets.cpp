/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets
 *
 * Medium (37.73%)
 * Total Accepted:    145292
 * Total Submissions: 385000
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [1],
 * ⁠ [2],
 * ⁠ [1,2,3],
 * ⁠ [1,3],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> nums, cur;
    int n;

    void next(int i) {
        if (i == n) { vv.push_back(cur); return; }

        cur.push_back(nums[i]); next(i+1);
        cur.pop_back(); next(i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        this->nums = nums;

        next(0);
        return vv;
    }
};
