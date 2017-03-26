/*
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum
 *
 * Medium (38.18%)
 * Total Accepted:    16765
 * Total Submissions: 43890
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * 
 * Note:
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int x = accumulate(nums.begin(), nums.end(), 0);
        if (x%2) return false;
        x /= 2;

        vector<bool> v(x+1, false);
        v[0] = true;

        for (auto num : nums)
            for (int i = x; i >= num; --i) v[i] = v[i] || v[i-num];

        return v[x];
    }
};
