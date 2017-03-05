/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx
 *
 * Easy (27.18%)
 * Total Accepted:    136942
 * Total Submissions: 503780
 * Testcase Example:  '0'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int i = 1, j = x;
        while (i <= j) {
            int m = i+(j-i)/2;
            int n = x / m;

            if (n == m && (x % m) == 0) return m;
            else if (n < m) j = m-1;
            else i = m+1;
        }
        return j;
    }
};
