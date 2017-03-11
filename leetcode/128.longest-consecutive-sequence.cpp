/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence
 *
 * Hard (35.73%)
 * Total Accepted:    94678
 * Total Submissions: 264993
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * 
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
 * length: 4.
 * 
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int x = 0;
        unordered_map<int, pair<int, int>> m;

        for (auto num : nums) {
            if (m.find(num) != m.end()) continue;
            int b = num, e = num;

            auto it = m.find(num-1);
            if (it != m.end()) b = min(b, it->second.first);

            auto it2 = m.find(num+1);
            if (it2 != m.end()) e = max(e, it2->second.second);

            m[b] = m[e] = m[num] = {b, e};
            x = max(x, e-b+1);
        }

        return x;
    }
};
