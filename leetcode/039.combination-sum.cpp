/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum
 *
 * Medium (36.54%)
 * Total Accepted:    141993
 * Total Submissions: 388593
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v, cur;
    int n, x;

    void next(int i, int sum) {
        if (sum == x) { vv.push_back(cur); return; }
        if (i >= n || sum > x) return;

        int k = (x-sum)/v[i];
        cur.insert(cur.end(), k, v[i]);
        while (k) {
            next(i+1, sum+k*v[i]);
            cur.pop_back();
            --k;
        }
        next(i+1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        x = target;
        v = candidates;
        n = v.size();
        sort(v.begin(), v.end());

        next(0, 0);

        return vv;
    }
};
