/*
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence
 *
 * Medium (38.40%)
 * Total Accepted:    35736
 * Total Submissions: 93039
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * 
 * Formally the function should:
 * Return true if there exists i, j, k  
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 
 * else return false.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 * 
 * 
 * Given [5, 4, 3, 2, 1],
 * return false.
 * 
 * 
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int m1 = numeric_limits<int>::max(), m2 = m1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > m2) return true;
            else if (nums[i] <= m1) m1 = nums[i];
            else if (nums[i] < m2) m2 = nums[i];
        }

        return false;
    }
};
