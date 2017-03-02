/*
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii
 *
 * Medium (51.01%)
 * Total Accepted:    10418
 * Total Submissions: 20425
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 *
 * You may assume the array's length is at most 10,000.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 2
 *
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 *
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 */
class Solution {
public:
    int minMoves2(vector<int>& nums) {
       size_t n = nums.size();
       if (n == 0) return 0;

       nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
       int k = nums[n / 2];

       int moves = accumulate(nums.begin(), nums.end(), 0,
               [k](int x, int v) { return x + abs(v - k); });
       return moves;
    }
};
