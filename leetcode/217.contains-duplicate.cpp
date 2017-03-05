/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate
 *
 * Easy (44.34%)
 * Total Accepted:    144411
 * Total Submissions: 325689
 * Testcase Example:  '[]'
 *
 * 
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) s.insert(num);
        return nums.size() > s.size();
    }
};
