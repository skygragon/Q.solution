/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements
 *
 * Medium (46.92%)
 * Total Accepted:    54616
 * Total Submissions: 116417
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * 
 * Note: 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (auto num : nums) ++m[num];

        using P = pair<int, int>;
        auto comp = [](const P &p1, const P &p2) { return p1.second > p2.second; };
        priority_queue<P, vector<P>, decltype(comp)> q(comp);

        for (auto &p : m) {
            q.push(p);
            if (q.size() > k) q.pop();
        }

        vector<int> v;
        while (!q.empty()) { v.push_back(q.top().first); q.pop(); }
        reverse(v.begin(), v.end());
        return v;
    }
};
