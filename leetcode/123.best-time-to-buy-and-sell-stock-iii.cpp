/*
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
 *
 * Hard (28.55%)
 * Total Accepted:    78810
 * Total Submissions: 276007
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), m;
        if (n < 2) return 0;

        vector<int> l(n, 0), r(n, 0);

        m = prices[0];
        for (int i = 1; i < n; ++i) { m = min(m, prices[i]); l[i] = max(l[i-1], prices[i]-m); }

        m = prices[n-1];
        for (int i = n-2; i >= 0; --i) { m = max(m, prices[i]); r[i] = max(r[i+1], m-prices[i]); }

        int x = max(r[0], l[n-1]);
        for (int i = 0; i < n-1; ++i) x = max(x, l[i]+r[i+1]);
        return x;
    }
};
