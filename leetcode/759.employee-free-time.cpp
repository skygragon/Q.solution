/*
 * [761] Employee Free Time
 *
 * https://leetcode.com/problems/employee-free-time/description/
 *
 * algorithms
 * Hard (50.34%)
 * Total Accepted:    1.8K
 * Total Submissions: 3.6K
 * Testcase Example:  '[[[1,2],[5,6]],[[1,3]],[[4,10]]]'
 *
 * 
 * We are given a list schedule of employees, which represents the working time
 * for each employee.
 * 
 * Each employee has a list of non-overlapping Intervals, and these intervals
 * are in sorted order.
 * 
 * Return the list of finite intervals representing common, positive-length
 * free time for all employees, also in sorted order.
 * 
 * 
 * Example 1:
 * 
 * Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
 * Output: [[3,4]]
 * Explanation:
 * There are a total of three employees, and all common
 * free time intervals would be [-inf, 1], [3, 4], [10, inf].
 * We discard any intervals that contain inf as they aren't finite.
 * 
 * 
 * Example 2:
 * 
 * Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
 * Output: [[5,6],[7,9]]
 * 
 * 
 * 
 * 
 * (Even though we are representing Intervals in the form [x, y], the objects
 * inside are Intervals, not lists or arrays.  For example,
 * schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is
 * not defined.)
 * 
 * Also, we wouldn't include intervals like [5, 5] in our answer, as they have
 * zero length.
 * 
 * 
 * Note:
 * schedule and schedule[i] are lists with lengths in range [1, 50].
 * 0 .
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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        int m = numeric_limits<int>::min();
        int M = numeric_limits<int>::max();

        auto comp = [](const Interval &i1, const Interval &i2) {
            return i1.end <= i2.start;
        };
        set<Interval, decltype(comp)> s(comp);

        s.insert(Interval(m, M));
        for (auto &v: schedule) {
            for (auto i: v) {
                while (i.start < i.end) {
                    auto it = s.lower_bound(i);
                    if (it == s.end() || comp(i, *it)) break;

                    Interval i2(*it), i3;
                    s.erase(it);

                    if (i2.start <= i.start) {
                        if (i2.end <= i.end) {
                            swap(i2.end, i.start);
                        } else {
                            i3.start = i.end;
                            i3.end = i2.end;
                            i2.end = i.start;
                            i.start = i.end = 0;
                        }
                    } else {
                        if (i.end <= i2.end) {
                            swap(i2.start, i.end);
                        } else {
                            i.start = i2.end;
                            i2.start = i2.end = 0;
                        }
                    }

                    if (i2.start < i2.end) s.insert(i2);
                    if (i3.start < i3.end) s.insert(i3);
                }
            }
        }

        s.erase(s.begin()); s.erase(--s.end());
        return vector<Interval>(s.begin(), s.end());
    }
};
