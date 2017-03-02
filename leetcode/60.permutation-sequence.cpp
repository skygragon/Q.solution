/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence
 *
 * Medium (27.44%)
 * Total Accepted:    75777
 * Total Submissions: 276155
 * Testcase Example:  '1\n1'
 *
 * The set [1,2,3,&#8230;,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string s;

        --k;    // ease calculating

        int sub = 1;
        for (int i = 1; i <= n; ++i) sub *= i;

        vector<int> v(n, 1);
        do {
            sub = sub / n;
            int nth = k / sub;
            k = k % sub;

            for (int i = 0; i < v.size(); ++i) {
                if (v[i] && nth-- == 0) {
                    v[i] = 0;
                    s += to_string(i+1);
                    break;
                }
            }
        } while (--n);

        return s;
    }
};
