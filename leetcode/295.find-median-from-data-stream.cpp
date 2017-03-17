/*
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream
 *
 * Hard (24.56%)
 * Total Accepted:    36980
 * Total Submissions: 150588
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5 
 * 
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * For example:
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * Credits:Special thanks to @Louis1992 for adding this problem and creating
 * all test cases.
 */
class MedianFinder {
public:
    priority_queue<int, vector<int>> maxH;
    priority_queue<int, vector<int>, std::greater<int>> minH;

    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minH.push(num);
        while (true) {
            while (!minH.empty() && !maxH.empty() && minH.top() < maxH.top()) {
                maxH.push(minH.top()); minH.pop();
            }

            int n = minH.size(), m = maxH.size();
            if (n > m+1) { maxH.push(minH.top()); minH.pop(); }
            else if (n+1 < m) { minH.push(maxH.top()); maxH.pop(); }
            else break;
        }
    }
    
    double findMedian() {
        int n = minH.size(), m = maxH.size();
        double x;
        if (n == m) x = (minH.top() + maxH.top()) / 2.0;
        else if (n+1 == m) x = maxH.top();
        else x = minH.top();
        return x;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
