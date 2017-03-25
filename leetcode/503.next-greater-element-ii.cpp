/*
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii
 *
 * Medium (46.27%)
 * Total Accepted:    4990
 * Total Submissions: 10782
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); if (n == 0) return {};
        stack<int> s;
        vector<int> v(n, -1);

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                int j = s.top(); s.pop();
                v[j] = nums[i];
            }
            s.push(i);
        }

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                int j = s.top(); s.pop();
                v[j] = nums[i];
            }
        }
        return v;
    }
};
