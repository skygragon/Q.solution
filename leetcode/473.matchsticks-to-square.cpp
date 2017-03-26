/*
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square
 *
 * Medium (34.03%)
 * Total Accepted:    5932
 * Total Submissions: 17419
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * Remember the story of Little Match Girl? By now, you know exactly what
 * matchsticks the little match girl has, please find out a way you can make
 * one square by using up all those matchsticks. You should not break any
 * stick, but you can link them up, and each matchstick must be used exactly
 * one time.
 * 
 * ⁠Your input will be several matchsticks the girl has, represented with their
 * stick length. Your output will either be true or false, to represent whether
 * you could make one square using all the matchsticks the little match girl
 * has.
 * 
 * Example 1:
 * 
 * Input: [1,1,2,2,2]
 * Output: true
 * 
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3,3,3,3,4]
 * Output: false
 * 
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 * 
 * 
 * 
 * Note:
 * 
 * The length sum of the given matchsticks is in the range of 0 to 10^9.
 * The length of the given matchstick array will not exceed 15.
 * 
 * 
 */
class Solution {
public:
    vector<int> nums, v;
    bool found;

    bool next(int i) {
        if (found) return found;
        if (accumulate(v.begin(), v.end(), 0) == 0) return found = true;
        if (i == nums.size()) return false;

        for (int j = 0; j < 4; ++j) {
            if (nums[i] > v[j]) continue;
            v[j] -= nums[i];
            if (next(i+1)) return true;
            v[j] += nums[i];
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 || sum % 4) return false;

        sort(nums.begin(), nums.end(), greater<int>());
        this->nums = nums;
        v.resize(4, sum/4);

        next(0);

        return found;
    }
};
