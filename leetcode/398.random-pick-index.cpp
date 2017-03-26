/*
 * [398] Random Pick Index
 *
 * https://leetcode.com/problems/random-pick-index
 *
 * Medium (41.50%)
 * Total Accepted:    16384
 * Total Submissions: 39485
 * Testcase Example:  '["Solution","pick"]\n[[[1,2,3,3,3]],[3]]'
 *
 * 
 * Given an array of integers with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array.
 * 
 * 
 * 
 * Note:
 * The array size can be very large. Solution that uses too much extra space
 * will not pass the judge.
 * 
 * 
 * Example:
 * 
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 * 
 * // pick(3) should return either index 2, 3, or 4 randomly. Each index should
 * have equal probability of returning.
 * solution.pick(3);
 * 
 * // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 * solution.pick(1);
 * 
 * 
 */
class Solution {
public:
    vector<int> v;

    Solution(vector<int> nums) {
        srand(time(NULL));
        v = nums;
    }
    
    int pick(int target) {
        int n = 0, x = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) continue;
            if (rand() % ++n == 0) x = i;
        }
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
