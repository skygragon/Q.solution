/*
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number
 *
 * Medium (37.22%)
 * Total Accepted:    33043
 * Total Submissions: 88733
 * Testcase Example:  '1\n[2,3,5]'
 *
 * 
 * ⁠   Write a program to find the nth super ugly number.
 * 
 * 
 * 
 * ⁠   Super ugly numbers are positive numbers whose all prime factors are in
 * the given prime list
 * ⁠   primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28,
 * 32]
 * ⁠is the sequence of the first 12 super ugly numbers given primes
 * ⁠   = [2, 7, 13, 19] of size 4.
 * 
 * 
 * 
 * ⁠   Note:
 * ⁠   (1) 1 is a super ugly number for any given primes.
 * ⁠   (2) The given numbers in primes are in ascending order.
 * ⁠   (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * ⁠   (4) The nth super ugly number is guaranteed to fit in a 32-bit signed
 * integer.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        using P = pair<long long, long long>;
        auto comp = [](const P &p1, const P &p2) {
            return p1.first > p2.first;
        };
        priority_queue<P, vector<P>, decltype(comp)> q(comp);
        q.push({1, -1});

        unordered_set<long long> s;

        long long x = 0, y = 0, m = primes.size();
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            x = p.first; y = p.second;

            if (s.find(x) == s.end()) {
                if (--n == 0) break;
                q.push({x, -1});
                s.insert(x);
            }

            if (y > -1) x /= primes[y];
            if (y < m-1) { ++y; q.push({x*primes[y], y}); }
        }
        return x;
    }
};
