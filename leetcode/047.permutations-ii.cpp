/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii
 *
 * Medium (31.46%)
 * Total Accepted:    107833
 * Total Submissions: 342351
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * 
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * 
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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

        set<int> used;
        for (int j = i; j < n; ++j) {
            if (j > i && nums[i] == nums[j]) continue;
            if (used.find(nums[j]) != used.end()) continue;

            swap(nums[i], nums[j]); next(i+1);
            swap(nums[i], nums[j]);
            used.insert(nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        n = nums.size();
        next(0);
        return vv;
    }
};
