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
        --k;    // ease calculating

        int p = 1; for (int i = 1; i <= n; ++i) p *= i;

        string s;
        vector<bool> used(n+1, false);
        do {
            p = p / n; int nth = k / p; k = k % p;

            for (int i = 1; i < used.size(); ++i) {
                if (used[i]) continue;
                if (nth-- == 0) { used[i] = true; s += to_string(i); break; }
            }
        } while (--n);

        return s;
    }
};
