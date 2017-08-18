/*
 * [600] Non-negative Integers without Consecutive Ones
 *
 * https://leetcode.com/problems/non-negative-integers-without-consecutive-ones
 *
 * algorithms
 * Hard (28.96%)
 * Total Accepted:    2.9K
 * Total Submissions: 9.9K
 * Testcase Example:  '1'
 *
 * Given a positive integer n, find the number of non-negative integers less
 * than or equal to n, whose binary representations do NOT contain consecutive
 * ones.
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: 5
 * Explanation: 
 * Here are the non-negative integers <= 5 with their corresponding binary
 * representations:
 * 0 : 0
 * 1 : 1
 * 2 : 10
 * 3 : 11
 * 4 : 100
 * 5 : 101
 * Among them, only integer 3 disobeys the rule (two consecutive ones) and the
 * other 5 satisfy the rule. 
 * 
 * 
 * 
 * Note:
 * 1 <= n <= 109
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, int> cache;

    unsigned findHighPow(unsigned x) {
        for (int i = 31; i >= 0; --i) {
            if (x & (1 << i)) return 1 << i;
        }
        return 0;
    }

    int findIntegers(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (n == 1) return 2;

        if (cache.find(n) != cache.end()) return cache[n];

        int v = 0, x = n;
        int y = findHighPow(x);
        v += findIntegers(y-1);
        x -= y;

        y = y >> 1;
        if (x < y) {
            v += findIntegers(x);
        } else {
            v += findIntegers(y-1);
        }

        return cache[n] = v;
    }
};
