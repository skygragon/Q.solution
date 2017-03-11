/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs
 *
 * Easy (43.32%)
 * Total Accepted:    15281
 * Total Submissions: 35208
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 */
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size(), k = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < n; ++i) {
            m.clear();
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                int d = dx * dx + dy * dy;
                ++m[d];
            }
            for (auto &p : m) {
                int x = p.second;
                if (x < 2) continue;
                k += x * (x-1);
            }
        }

        return k;
    }
};
