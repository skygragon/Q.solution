/*
 * [352] Data Stream as Disjoint Intervals
 *
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals
 *
 * Hard (39.27%)
 * Total Accepted:    11043
 * Total Submissions: 28122
 * Testcase Example:  '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an, ...,
 * summarize the numbers seen so far as a list of disjoint intervals.
 * 
 * For example, suppose the integers from the data stream are 1, 3, 7, 2, 6,
 * ..., then the summary will be:
 * 
 * [1, 1]
 * [1, 1], [3, 3]
 * [1, 1], [3, 3], [7, 7]
 * [1, 3], [7, 7]
 * [1, 3], [6, 7]
 * 
 * 
 * Follow up:
 * What if there are lots of merges and the number of disjoint intervals are
 * small compared to the data stream's size?
 * 
 * 
 * Credits:Special thanks to @yunhong for adding this problem and creating most
 * of the test cases.
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
static auto comp = [](const Interval &x, const Interval &y) {
    return x.end+1 < y.start;
};
static set<Interval, decltype(comp)> s{comp};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int val) {
        Interval p(val, val);
        while (true) {
            auto it = s.find(p);
            if (it == s.end()) { s.insert(p); return; }

            p.start = min(p.start, it->start);
            p.end = max(p.end, it->end);
            s.erase(it);
        }
    }
    
    vector<Interval> getIntervals() {
        return {s.begin(), s.end()};
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
