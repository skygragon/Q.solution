/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii
 *
 * Hard (43.45%)
 * Total Accepted:    59035
 * Total Submissions: 135762
 * Testcase Example:  '1'
 *
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 * 
 * 
 */
class Solution {
public:
    int n, count;
    vector<bool> col, l, r;

    void next(int i) {
        if (i == n) { ++count; return; }

        for (int j = 0; j < n; ++j) {
            if (col[j] || l[i+j] || r[n-1+i-j]) continue;

            col[j] = l[i+j] = r[n-1+i-j] = true;
            next(i+1);
            col[j] = l[i+j] = r[n-1+i-j] = false;
        }
    }

    int totalNQueens(int n) {
        this->n = n;

        col.resize(n, false);
        l.resize(2*n-1, false);
        r.resize(2*n-1, false);

        next(0);

        return count;
    }
};
