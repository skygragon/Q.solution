/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii
 *
 * Hard (26.05%)
 * Total Accepted:    87000
 * Total Submissions: 333909
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * 
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 * 
 * 
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), i = 0, k = 0;
        while (i < n-1) {
            ++k;
            if (nums[i]+i >= n-1) break;

            int next = i;
            for (int j = i; j < n && j <= nums[i]+i; ++j) {
                if (nums[j]+j > nums[next]+next) next = j;
            }
            i = next;
        }

        return k;
    }
};
