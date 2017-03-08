/*
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element
 *
 * Medium (36.30%)
 * Total Accepted:    102281
 * Total Submissions: 281760
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return
 * its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that num[-1] = num[n] = -∞.
 * 
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function
 * should return the index number 2.
 * 
 * click to show spoilers.
 * 
 * Note:
 * Your solution should be in logarithmic complexity.
 * 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int i = 1, j = nums.size()-2;
        while (i <= j) {
            int m = (i+j)/2;
            if (nums[m]>nums[m-1] && nums[m]>nums[m+1]) return m;
            else if (nums[m]<nums[m-1]) j = m-1;
            else i = m+1;
        }
        return i;
    }
};
