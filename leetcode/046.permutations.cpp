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

    void next(vector<int>& v, int k) {
        int n = v.size();
        if (k == n-1) {
            vv.push_back(v);
            return;
        }
        for (int i = k; i < n; ++i) {
            swap(v[k], v[i]);
            next(v, k+1);
            swap(v[k], v[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        next(nums, 0);
        return vv;
    }
};
