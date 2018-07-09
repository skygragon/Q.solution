/*
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array
 *
 * algorithms
 * Easy (18.57%)
 * Total Accepted:    2.4K
 * Total Submissions: 12.8K
 * Testcase Example:  '[4,2,3]'
 *
 * 
 * Given an array with n integers, your task is to check if it could become
 * non-decreasing by modifying at most 1 element.
 * 
 * 
 * 
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for
 * every i (1 <= i < n).
 * 
 * 
 * Example 1:
 * 
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 * 
 * 
 * 
 * Note:
 * The n belongs to [1, 10,000].
 * 
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int x = 0;
        stack<int> s;
        for (int num : nums) {
            if (s.empty() || s.top() <= num) {
                s.push(num);
                continue;
            }

            int last = s.top(); s.pop();
            if (s.empty() || s.top() <= num) {
                last = num;
            } else {
                num = last;
            }
            if (++x == 2) return false;
            s.push(last); s.push(num);
        }
        return true;
    }
};
