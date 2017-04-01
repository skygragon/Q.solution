/*
 * [135] Candy
 *
 * https://leetcode.com/problems/candy
 *
 * Hard (24.13%)
 * Total Accepted:    64798
 * Total Submissions: 268543
 * Testcase Example:  '[0]'
 *
 * 
 * There are N children standing in a line. Each child is assigned a rating
 * value. 
 * 
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> v(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) v[i] = v[i-1]+1;
        }
        for (int i = n-1; i > 0; --i) {
            if (ratings[i] < ratings[i-1]) v[i-1] = max(v[i-1], v[i]+1);
        }

        return accumulate(v.begin(), v.end(), 0);
    }
};
