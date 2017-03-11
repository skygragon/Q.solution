/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals
 *
 * Medium (28.86%)
 * Total Accepted:    109069
 * Total Submissions: 377821
 * Testcase Example:  '[]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        auto comp = [](const Interval &r1, const Interval &r2) {
            return r1.end < r2.start;
        };
        set<Interval, decltype(comp)> s(comp);
        for (auto r : intervals) {
            while (true) {
                auto it = s.find(r);
                if (it == s.end()) break;
                s.erase(it);
                r.start = min(it->start, r.start);
                r.end = max(it->end, r.end);
            }
            s.insert(r);
        }

        vector<Interval> v(s.begin(), s.end());
        return v;
    }
};
