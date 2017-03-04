/*
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range
 *
 * Medium (33.34%)
 * Total Accepted:    50616
 * Total Submissions: 151779
 * Testcase Example:  '0\n0'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * 
 * For example, given the range [5, 7], you should return 4.
 * 
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int getPower(int n) {
        while (n & (n-1)) n = n & (n-1);
        return n;
    }

    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;

        int p1 = getPower(m);
        int p2 = getPower(n);

        if (p1 != p2) return 0;
        return p1 | rangeBitwiseAnd(m-p1, n-p1);
    }
};
