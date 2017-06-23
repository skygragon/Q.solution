/*
 * [625] Minimum Factorization
 *
 * https://leetcode.com/problems/minimum-factorization
 *
 * Medium (28.47%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '48'
 *
 * Given a positive integer a, find the smallest positive integer b whose
 * multiplication of each digit equals to a. 
 * 
 * 
 * If there is no answer or the answer is not fit in 32-bit signed integer,
 * then return 0.
 * 
 * 
 * Example 1
 * Input:
 * 48 
 * Output:
 * 68
 * 
 * 
 * 
 * Example 2
 * Input: 
 * 15
 * 
 * Output:
 * 35
 * 
 */
class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 4) return a;

        vector<int> v;
        for (int i = 9; i >= 2;) {
            if (a % i) {
                --i;
                continue;
            }
            v.push_back(i);
            a /= i;
        }
        if (a != 1) return 0;

        reverse(v.begin(), v.end());
        int cur = 0, next = 0;
        for (auto x : v) {
            next = cur * 10 + x;
            if (next / 10 < cur) return 0;
            cur = next;
        }
        return cur;
    }
};
