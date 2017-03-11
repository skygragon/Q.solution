/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii
 *
 * Easy (31.79%)
 * Total Accepted:    98593
 * Total Submissions: 310189
 * Testcase Example:  '[]\n0'
 *
 * 
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            auto it = m.find(x);
            if (it != m.end()) {
                if (i - it->second <= k) return true;
            }
            m[x] = i;
        }
        return false;
    }
};
