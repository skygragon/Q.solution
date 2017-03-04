/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position
 *
 * Easy (39.16%)
 * Total Accepted:    151306
 * Total Submissions: 386389
 * Testcase Example:  '[1]\n0'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * 
 * Here are few examples.
 * [1,3,5,6], 5 &#8594; 2
 * [1,3,5,6], 2 &#8594; 1
 * [1,3,5,6], 7 &#8594; 4
 * [1,3,5,6], 0 &#8594; 0
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int m = (j + i) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) j = m-1;
            else i = m+1;
        }

        return i;
    }
};
