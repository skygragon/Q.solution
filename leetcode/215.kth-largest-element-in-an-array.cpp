/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 * Medium (38.09%)
 * Total Accepted:    114115
 * Total Submissions: 299545
 * Testcase Example:  '[1]\n1'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> h(k+1, numeric_limits<int>::max());
        make_heap(h.begin(), h.end());

        for (auto num : nums) {
            pop_heap(h.begin(), h.end());
            h.pop_back();
            h.push_back(-num);
            push_heap(h.begin(), h.end());
        }

        pop_heap(h.begin(), h.end()); h.pop_back();
        pop_heap(h.begin(), h.end());
        return -h.back();
    }
};
