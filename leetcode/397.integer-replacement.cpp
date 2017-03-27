/*
 * [397] Integer Replacement
 *
 * https://leetcode.com/problems/integer-replacement
 *
 * Medium (29.50%)
 * Total Accepted:    15997
 * Total Submissions: 54165
 * Testcase Example:  '8'
 *
 * 
 * Given a positive integer n and you can do operations as follow:
 * 
 * 
 * 
 * 
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * 
 * 
 * 
 * 
 * What is the minimum number of replacements needed for n to become 1?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 8
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 7
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, int> m;

    int next(int n) {
        if (n == 1) return 0;
        if (m.find(n) != m.end()) return m[n];

        int x = numeric_limits<int>::max();
        if (n % 2 == 0) {
            x = min(x, next(n/2)+1);
        } else {
            x = min(x, next(n-1)+1);
            x = min(x, next(n/2+1)+2);
        }

        return m[n] = x;
    }

    int integerReplacement(int n) {
        return next(n);
    }
};
