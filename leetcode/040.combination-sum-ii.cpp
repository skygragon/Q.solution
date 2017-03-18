/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii
 *
 * Medium (31.93%)
 * Total Accepted:    102684
 * Total Submissions: 321523
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v, cur;
    unordered_map<int, int> count;
    int n, x;

    void next(int i, int sum) {
        if (sum == x) { vv.push_back(cur); return; }
        if (i == n || sum > x) return;

        int k = count[v[i]];
        cur.insert(cur.end(), k+1, v[i]);
        while (k >= 0) {
            cur.pop_back();
            next(i+1, sum+k*v[i]);
            --k;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto x : candidates)
            if (++count[x] == 1) v.push_back(x);

        n = v.size();
        x = target;

        next(0, 0);

        return vv;
    }
};
