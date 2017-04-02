/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers
 *
 * Medium (15.96%)
 * Total Accepted:    93108
 * Total Submissions: 583250
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        int NA = numeric_limits<int>::max();
        if (dividend == 0) return 0;
        if (divisor == 0) return NA;
        if (dividend == divisor) return 1;

        int sign = 1;
        if (dividend < 0) sign *= -1;
        if (divisor < 0) sign *= -1;

        long long d = labs(dividend);
        long long r = labs(divisor);

        vector<long long> v(32);
        long long x = r, n = 0;
        int i;
        for (i = 0; i < 32 && d >= x; ++i) { v[i] = x; x = x << 1; }

        --i;
        while (i >= 0) {
            if (d >= v[i]) { d -= v[i]; n += (1 << i); }
            --i;
        }

        if (sign > 0 && n < 0) return NA;
        return sign*n;
    }
};
