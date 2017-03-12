/*
 * [475] Heaters
 *
 * https://leetcode.com/problems/heaters
 *
 * Easy (29.89%)
 * Total Accepted:    10503
 * Total Submissions: 35136
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * Winter is coming! Your first job during the contest is to design a standard
 * heater with fixed warm radius to warm all the houses.
 * 
 * Now, you are given positions of houses and heaters on a horizontal line,
 * find out minimum radius of heaters so that all houses could be covered by
 * those heaters.
 * 
 * So, your input will be the positions of houses and heaters seperately, and
 * your expected output will be the minimum radius standard of heaters.
 * 
 * Note:
 * 
 * Numbers of houses and heaters you are given are non-negative and will not
 * exceed 25000.
 * Positions of houses and heaters you are given are non-negative and will not
 * exceed 10^9.
 * As long as a house is in the heaters' warm radius range, it can be warmed.
 * All the heaters follow your radius standard and the warm radius will the
 * same.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3],[2]
 * Output: 1
 * Explanation: The only heater was placed in the position 2, and if we use the
 * radius 1 standard, then all the houses can be warmed.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4],[1,4]
 * Output: 1
 * Explanation: The two heater was placed in the position 1 and 4. We need to
 * use radius 1 standard, then all the houses can be warmed.
 * 
 * 
 */
class Solution {
public:
    int find(vector<int> &v, int x, bool isLeft) {
        int n = v.size(), i = 0, j = n-1;
        if (x > v[n-1]) return isLeft ? -1 : v[n-1];
        if (x < v[0]) return isLeft ? v[0] : -1;

        while (i <= j) {
            int m = (i+j)/2;
            if (v[m] == x) return x;
            else if (v[m] > x) j = m-1;
            else i = m+1;
        }
        return isLeft ? v[i] : v[j];
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        auto it = unique(houses.begin(), houses.end());
        houses.erase(it, houses.end());

        int n = heaters.size(), x = 0, last = -1;
        for (int i = 0; i < n; ++i) {
            int b = numeric_limits<int>::min();
            int e = numeric_limits<int>::max();

            if (i > 0) b = (heaters[i] + heaters[i-1]) / 2;
            if (i < n-1) e = (heaters[i] + heaters[i+1]) / 2;

            if (i > 0) b = max(b, last+1);

            b = find(houses, b, true);
            e = find(houses, e, false);

            last = e;

            if (b == -1 || e == -1 || b > e) continue;

            int d = max(abs(heaters[i] - b), abs(heaters[i] - e));
            x = max(x, d);
        }
        return x;
    }
};
