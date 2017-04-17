/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations
 *
 * Medium (41.28%)
 * Total Accepted:    148841
 * Total Submissions: 360536
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a collection of distinct numbers, return all possible permutations.
 * 
 * 
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * 
 * [
 * [1,2,3],
 * [1,3,2],
 * [2,1,3],
 * [2,3,1],
 * [3,1,2],
 * [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> nums;
    int n;

    void next(int i) {
        if (i == n-1) { vv.push_back(nums); return; }
        for (int j = i; j < n; ++j) {
            swap(nums[i], nums[j]); next(i+1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        next(0);
        return vv;
    }
};
