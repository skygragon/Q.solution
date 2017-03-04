/*
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 *
 * Easy (47.80%)
 * Total Accepted:    58552
 * Total Submissions: 122544
 * Testcase Example:  '[2,3,4]\n6'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2. Please note
 * that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() -1;
        while (i < j) {
            int x = numbers[i] + numbers[j];

            if (x == target) return {i+1, j+1};
            else if (x > target) --j;
            else ++i;
        }
        return {};
    }
};
