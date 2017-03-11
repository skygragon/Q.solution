/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range
 *
 * Medium (31.00%)
 * Total Accepted:    122569
 * Total Submissions: 395354
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 */
class Solution {
public:
    int find(vector<int> &v, int x, bool isLeft) {
        int i = 0, j = v.size()-1, k = -1;
        while (i <= j) {
            int m = i+(j-i)/2;
            if (v[m] == x) {
                k = m;
                if (isLeft) j = m-1;
                else i = m+1;
            } else if (v[m] > x) {
                j = m-1;
            } else {
                i = m+1;
            }
        }

        return k;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {
            find(nums, target, true),
            find(nums, target, false)
        };
    }
};
