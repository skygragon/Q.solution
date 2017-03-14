/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval
 *
 * Hard (26.71%)
 * Total Accepted:    86342
 * Total Submissions: 322684
 * Testcase Example:  '[]\n[5,7]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * 
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * 
 * 
 * 
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 * 
 * 
 * 
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto comp = [](const Interval& i1, const Interval& i2) {
            return i1.end < i2.start;
        };
        set<Interval, decltype(comp)> s(intervals.begin(), intervals.end(), comp);

        Interval i = newInterval;
        while (true) {
            auto it = s.find(i);
            if (it == s.end()) {
                s.insert(i);
                break;
            }

            s.erase(it);
            i.start = min(i.start, it->start);
            i.end = max(i.end, it->end);
        }

        return vector<Interval>(s.begin(), s.end());
    }
};
