/*
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals
 *
 * Medium (40.14%)
 * Total Accepted:    9222
 * Total Submissions: 22972
 * Testcase Example:  '[[1,2]]'
 *
 * 
 * Given a collection of intervals, find the minimum number of intervals you
 * need to remove to make the rest of the intervals non-overlapping.
 * 
 * 
 * Note:
 * 
 * You may assume the interval's end point is always bigger than its start
 * point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't
 * overlap each other.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [ [1,2], [2,3], [3,4], [1,3] ]
 * 
 * Output: 1
 * 
 * Explanation: [1,3] can be removed and the rest of intervals are
 * non-overlapping.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [ [1,2], [1,2], [1,2] ]
 * 
 * Output: 2
 * 
 * Explanation: You need to remove two [1,2] to make the rest of intervals
 * non-overlapping.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [ [1,2], [2,3] ]
 * 
 * Output: 0
 * 
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval &x, const Interval &y) {
            return x.end < y.end ||
                   (x.end == y.end && x.start > y.start);
        };
        sort(intervals.begin(), intervals.end(), comp);

        int k = -1, n = intervals.size(), x = 0;
        for (int i = 0; i < n; ++i) {
            if (k == -1 || intervals[k].end <= intervals[i].start) {
                k = i;
            } else {
                ++x;
            }
        }

        return x;
    }
};
