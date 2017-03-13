/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii
 *
 * Medium (34.58%)
 * Total Accepted:    100208
 * Total Submissions: 289176
 * Testcase Example:  '[1,2,2]'
 *
 * 
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> nums, cur;

    void next(int i) {
        int n = nums.size();
        if (i == n) {
            vv.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        next(i+1);
        cur.pop_back();

        while (i < n-1 && nums[i] == nums[i+1]) ++i;
        next(i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;

        next(0);

        return vv;
    }
};
