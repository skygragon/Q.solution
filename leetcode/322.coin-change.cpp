/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change
 *
 * Medium (26.16%)
 * Total Accepted:    53044
 * Total Submissions: 202768
 * Testcase Example:  '[1]\n0'
 *
 * 
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * 
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * 
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    unordered_map<int,int> m;
    vector<int> v;

    int next(int num) {
        if (m.find(num) != m.end()) return m[num];
        if (num <= 0) return m[num] = max(num, -1);

        int x = -1;
        for (auto coin : v) {
            int cur = next(num-coin);
            if (cur >= 0) {
                if (x == -1) x = cur+1;
                x = min(x, cur+1);
            }
        }
        return m[num] = x;
    }

    int coinChange(vector<int>& coins, int amount) {
        v = coins;
        return next(amount);
    }
};
