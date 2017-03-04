/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations
 *
 * Medium (38.27%)
 * Total Accepted:    106121
 * Total Submissions: 277234
 * Testcase Example:  '4\n2'
 *
 * 
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * 
 * 
 * [
 * [2,4],
 * [3,4],
 * [2,3],
 * [1,2],
 * [1,3],
 * [1,4],
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;
    int n;
    int k;

    void next(int i) {
        if (i == k) return vv.push_back(v);

        for (int j = i > 0 ? v[i-1]+1 : 1; j <= n; ++j) {
            v[i] = j;
            next(i+1);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        v.resize(k, 0);

        next(0);
        return vv;

    }
};
