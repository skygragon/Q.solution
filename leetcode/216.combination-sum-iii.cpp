/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii
 *
 * Medium (42.86%)
 * Total Accepted:    59367
 * Total Submissions: 138497
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * 
 * 
 * ⁠Example 1:
 * Input:  k = 3,  n = 7
 * Output: 
 * 
 * [[1,2,4]]
 * 
 * 
 * ⁠Example 2:
 * Input:  k = 3,  n = 9
 * Output: 
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;

    int n, k;

    void next(int i, int s) {
        if (i == k) {
            if (s == n) vv.push_back(v);
            return;
        }

        for (int j = 1; j <= 9; ++j) {
            if (i > 0 && v[i-1] >= j) continue;
            v[i] = j;
            next(i+1, s+j);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        v.resize(k);
        this->k = k;
        this->n = n;

        next(0, 0);

        return vv;
    }
};
