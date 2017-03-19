/*
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code
 *
 * Medium (39.83%)
 * Total Accepted:    82249
 * Total Submissions: 206502
 * Testcase Example:  '0'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * 
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * 
 * For example, [0,2,3,1] is also a valid gray code sequence according to the
 * above definition.
 * 
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v = {0};
        if (n == 0) return v;

        for (int i = 1; i <= n; ++i) {
            int k = v.size();
            vector<int> v1(k*2);
            for (int j = 0; j < k; ++j) {
                v1[j] = v[j];
                v1[2*k-j-1] = (1 << (i-1)) + v[j];
            }
            v1.swap(v);
        }

        return v;
    }
};
