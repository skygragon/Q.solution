/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element
 *
 * Easy (45.30%)
 * Total Accepted:    175554
 * Total Submissions: 387508
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than &lfloor; n/2 &rfloor; times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, n = 0;
        for (auto num : nums) {
            if (n == 0) {
                x = num;
                ++n;
            } else if (num == x) {
                ++n;
            } else {
                --n;
            }
        }
        return x;
    }
};
