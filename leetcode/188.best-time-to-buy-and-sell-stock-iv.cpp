/*
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
 *
 * Hard (24.03%)
 * Total Accepted:    42806
 * Total Submissions: 178023
 * Testcase Example:  '2\n[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), x = 0;
        if (n < 2 || k < 1) return 0;

        if (k >= n/2) {
            for (int i = 1; i < n; ++i) x += max(0, prices[i]-prices[i-1]);
            return x;
        }

        vector<int> buy(n, 0);
        vector<int> sell(n, 0), sell2(n, 0);

        for (int i = 0; i < n; ++i) buy[i] = -prices[i];

        for (int i = 0; i < k; ++i) {
            for (int j = 1; j < n; ++j) {
                buy[j] = buy[j-1] + prices[j-1] - prices[j];
                if (i > 0) buy[j] = max(buy[j], sell2[j-1]-prices[j]);
                x = max(x, buy[j]);

                sell[j] = max(sell[j-1]-prices[j-1]+prices[j], buy[j-1]+prices[j]);
                x = max(x, sell[j]);
            }
            sell2 = sell;
        }
        return x;
    }
};
