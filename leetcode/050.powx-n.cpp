/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n
 *
 * Medium (26.86%)
 * Total Accepted:    137028
 * Total Submissions: 510541
 * Testcase Example:  '8.88023\n3'
 *
 * Implement pow(x, n).
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        int m = abs(n);
        vector<int> v;
        while (m) { v.push_back(m%2 ? 1 : 0); m /= 2; }

        double s = 1;
        for (int i = v.size()-1; i >= 0; --i) {
            s *= s;
            if (v[i] == 1) s *= x;
        }

        return n > 0 ? s : 1 / s;
    }
};
