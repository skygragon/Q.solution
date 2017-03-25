/*
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator
 *
 * Medium (39.98%)
 * Total Accepted:    31873
 * Total Submissions: 79706
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * 
 * Example 2:
 * Given the list [1,[4,[6]]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,4,6].
 * 
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    using Iter = vector<NestedInteger>::iterator;
    using P = pair<Iter, Iter>;
    stack<P> s;

    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push({nestedList.begin(), nestedList.end()});
        check();
    }

    void check() {
        while (!s.empty()) {
            auto &p = s.top();
            if (p.first == p.second) {
                s.pop();
                if (!s.empty()) ++s.top().first;
                continue;
            } else if (p.first->isInteger()) {
                break;
            } else {
                auto &v = p.first->getList();
                s.push({v.begin(), v.end()});
                continue;
            }
        }
    }

    int next() {
        auto &p = s.top();
        int x = p.first->getInteger();

        ++p.first;
        check();

        return x;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
