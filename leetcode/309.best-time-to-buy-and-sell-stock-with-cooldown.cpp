/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
 *
 * Medium (40.09%)
 * Total Accepted:    37103
 * Total Submissions: 92533
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the
 * following restrictions:
 * 
 * 
 * ⁠   You may not engage in multiple transactions at the same time (ie, you
 * must sell the stock before you buy again).
 * ⁠   After you sell your stock, you cannot buy stock on next day. (ie,
 * cooldown 1 day)
 * 
 * 
 * Example:
 * 
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), x = 0;
        if (n == 0) return 0;

        vector<int> sell(n, 0), buy(n, 0);
        sell[0] = 0; buy[0] = -prices[0];

        for (int i = 1; i < n; ++i) {
            sell[i] = buy[i-1]+prices[i];
            sell[i] = max(sell[i], sell[i-1]-prices[i-1]+prices[i]);
            x = max(x, sell[i]);

            buy[i] = buy[i-1]+prices[i-1]-prices[i];
            if (i > 1) buy[i] = max(buy[i], sell[i-2]-prices[i]);
            x = max(x, buy[i]);
        }
        return x;
    }
};
