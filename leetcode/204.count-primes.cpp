/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes
 *
 * Easy (26.23%)
 * Total Accepted:    102377
 * Total Submissions: 390376
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<int> v(n+1, 1);
        int x = 0;
        for (int i = 2; i < n; ++i) {
            if (v[i]) {
                ++x;
                for (int j = 2; i*j <= n; ++j) v[i*j] = 0;
            }
        }
        return x;
    }
};
