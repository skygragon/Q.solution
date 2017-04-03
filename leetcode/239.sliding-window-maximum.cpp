/*
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum
 *
 * Hard (32.07%)
 * Total Accepted:    54929
 * Total Submissions: 171218
 * Testcase Example:  '[]\n0'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 * 
 * Note: 
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for
 * non-empty array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 * 
 * ⁠ How about using a data structure such as deque (double-ended queue)?
 * ⁠ The queue size need not be the same as the window’s size.
 * ⁠ Remove redundant elements and the queue should store only elements that
 * need to be considered.
 * 
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};

        vector<int> v(n-k+1);
        deque<int> d;

        for (int i = 0; i < n; ++i) {
            while (!d.empty() && d.front() <= i-k) d.pop_front();
            while (!d.empty() && nums[d.back()] < nums[i]) d.pop_back();
            d.push_back(i);
            if (i >= k-1) v[i+1-k] = nums[d.front()];
        }
        return v;
    }
};
