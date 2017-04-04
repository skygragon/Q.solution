/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line
 *
 * Hard (15.48%)
 * Total Accepted:    75872
 * Total Submissions: 490186
 * Testcase Example:  '[]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        while (b) { int x = a % b; a = b; b = x; }
        return a;
    }

    int maxPoints(vector<Point>& points) {
        int x = 0, n = points.size();

        unordered_map<int, int> m;
        for (auto &p : points) x = max(x, ++m[p.x]); m.clear();
        for (auto &p : points) x = max(x, ++m[p.y]); m.clear();

        map<pair<int, int>, int> m1;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;

            int dup = 1;
            auto &p1 = points[i];

            for (int j = i+1; j < n; ++j) {
                auto &p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y) { visited[j] = true; ++dup; continue; }
                if (p1.x == p2.x || p1.y == p2.y) continue;

                int dx = p2.x - p1.x, dy = p2.y - p1.y, sign = 1;
                if (dx < 0) { sign *= -1; dx = -dx; }
                if (dy < 0) { sign *= -1; dy = -dy; }

                int m = gcd(dy, dx); dx /= m; dy /= m;
                ++m1[{dy*sign, dx}];
            }

            for (auto &p : m1) x = max(x, p.second+dup);
            m1.clear();
        }

        return x;
    }
};
