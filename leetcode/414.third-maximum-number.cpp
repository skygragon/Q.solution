/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number
 *
 * Easy (26.96%)
 * Total Accepted:    24087
 * Total Submissions: 89355
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> v(4, 0);
        vector<bool> v2(4, false);

        for (auto num : nums) {
            // remove duplicate
            if (v2[1] && num == v[1]) continue;
            if (v2[2] && num == v[2]) continue;
            if (v2[3] && num == v[3]) continue;

            v[0] = num; v2[0] = true;
            for(int i = 1; i < 4; ++i) {
                if (v2[i] && v[i] > num) break;
                swap(v[i], v[i-1]);
                swap(v2[i], v2[i-1]);
            }
        }

        return v2[1] ? v[1] : v.back();
    }
};
