/*
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 *
 * Easy (45.87%)
 * Total Accepted:    127430
 * Total Submissions: 277759
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at the
 * same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x = 0, head = 0;
        prices.push_back(numeric_limits<int>::min());

        stack<int> s;
        for (auto p : prices) {
            if (!s.empty() && s.top() > p) {
                x += s.top() - head;
                while (!s.empty()) s.pop();
            }

            if (s.empty()) head = p;
            s.push(p);
        }

        return x;
    }
};
