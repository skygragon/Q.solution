/*
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (53.65%)
 * Total Accepted:    6.8K
 * Total Submissions: 12.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures, produce a list that, for each day in the
 * input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73],
 * your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> v(n, 0);

        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && t[s.top()] < t[i]) { v[s.top()] = i-s.top(); s.pop(); }
            s.push(i);
        }
        return v;
    }
};
