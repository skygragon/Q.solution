/*
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers
 *
 * Medium (40.21%)
 * Total Accepted:    15777
 * Total Submissions: 39206
 * Testcase Example:  '13'
 *
 * 
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * 
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * 
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
class Solution {
public:
    vector<int> v;
    int n;

    void next(int k) {
        k *= 10;
        for (int i = 0; i <= 9; ++i) {
            if (k == 0 && i == 0) continue;

            int cur = k + i; if (cur > n) return;
            v.push_back(cur);
            next(cur);
        }
    }

    vector<int> lexicalOrder(int n) {
        this->n = n;
        next(0);
        return v;
    }
};
