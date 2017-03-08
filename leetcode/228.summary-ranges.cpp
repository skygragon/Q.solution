/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges
 *
 * Medium (28.58%)
 * Total Accepted:    71588
 * Total Submissions: 250424
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        int n = nums.size();
        if (n == 0) return v;

        int last = nums[0];
        for (int i = 1; i <= n; ++i) {
            if (i < n && nums[i] == nums[i-1]+1) continue;

            if (nums[i-1] == last) v.push_back(to_string(last));
            else v.push_back(to_string(last) + "->" + to_string(nums[i-1]));
            if (i < n) last = nums[i];
        }
        return v;
    }
};
