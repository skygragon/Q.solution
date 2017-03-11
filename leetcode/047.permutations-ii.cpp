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

    void next(vector<int>& v, int k) {
        int n = v.size();
        if (k == n-1) {
            vv.push_back(v);
            return;
        }

        set<int> s;
        for (int i = k; i < n; ++i) {
            if (i > k && v[i] == v[k]) continue;
            if (s.find(v[i]) != s.end()) continue;

            swap(v[k], v[i]);
            next(v, k+1);
            swap(v[k], v[i]);
            s.insert(v[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        next(nums, 0);
        return vv;
    }
};
