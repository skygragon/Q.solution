/*
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks
 *
 * Easy (49.78%)
 * Total Accepted:    5279
 * Total Submissions: 10651
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 */
/*
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks
 *
 * Easy (49.78%)
 * Total Accepted:    5279
 * Total Submissions: 10651
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) m[nums[i]] = i;

        sort(nums.begin(), nums.end(), greater<int>());

        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            int k = m[nums[i]];
            switch(i) {
                case 0: v[k] = "Gold Medal"; break;
                case 1: v[k] = "Silver Medal"; break;
                case 2: v[k] = "Bronze Medal"; break;
                default: v[k] = to_string(i+1);
            }
        }
        return v;
    }
};

