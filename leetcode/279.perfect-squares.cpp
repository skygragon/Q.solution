/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares
 *
 * Medium (35.60%)
 * Total Accepted:    67275
 * Total Submissions: 188974
 * Testcase Example:  '1'
 *
 * 
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * 
 * 
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
 * return 2 because 13 = 4 + 9.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int NA = numeric_limits<int>::max();
    unordered_map<int, int> cache;

    int next(int n) {
        if (n == 0) return 0;
        if (cache[n] > 0 && cache[n] < NA) return cache[n];

        int x = NA;
        for (int j = sqrt(n); j > 0; --j) {
            int k = n/(j*j);
            int y = next(n-k*j*j);
            if (y != NA) x = min(x, y+k);
        }

        cache[n] = x;
        return x;
    }

    int numSquares(int n) {
        return next(n);
    }
};
