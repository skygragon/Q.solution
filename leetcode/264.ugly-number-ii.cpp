/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii
 *
 * Medium (31.82%)
 * Total Accepted:    52216
 * Total Submissions: 164088
 * Testcase Example:  '1'
 *
 * 
 * Write a program to find the n-th ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number, and n does not exceed
 * 1690.
 * 
 * 
 * 
 * ⁠ The naive approach is to call isUgly for every number until you reach the
 * nth one. Most numbers are not ugly. Try to focus your effort on generating
 * only the ugly ones.
 * ⁠ An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly
 * number.
 * ⁠ The key is how to maintain the order of the ugly numbers. Try a similar
 * approach of merging from three sorted lists: L1, L2, and L3.
 * ⁠ Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2
 * * 3, L3 * 5).
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        using INT = long long;
        priority_queue<INT, vector<INT>, greater<INT>> q;
        q.push(1);

        INT x;
        while (n) {
            x = q.top();
            while (!q.empty() && x == q.top()) q.pop();

            --n;
            if (x*2 > x) q.push(x * 2);
            if (x*3 > x) q.push(x * 3);
            if (x*5 > x) q.push(x * 5);
        }

        return x;
    }
};
