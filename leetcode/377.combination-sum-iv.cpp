/*
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv
 *
 * Medium (41.68%)
 * Total Accepted:    30457
 * Total Submissions: 73046
 * Testcase Example:  '[1,2,3]\n4'
 *
 * ⁠Given an integer array with all positive numbers and no duplicates, find
 * the number of possible combinations that add up to a positive integer
 * target.
 * 
 * Example:
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    vector<int> v;
    unordered_map<int, int> m;

    int next(int n) {
        if (m.find(n) != m.end()) return m[n];

        int x = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (n < v[i]) continue;
            if (n == v[i]) ++x;
            else x += next(n - v[i]);
        }
        return m[n] = x;
    }

    int combinationSum4(vector<int>& nums, int target) {
        v = nums;
        return next(target);
    }
};
