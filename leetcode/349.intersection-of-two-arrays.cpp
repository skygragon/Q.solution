/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays
 *
 * Easy (46.12%)
 * Total Accepted:    76019
 * Total Submissions: 164723
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * 
 * Note:
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        unordered_set<int> s;
        for (auto num : nums1)
            s.insert(num);
        for (auto num : nums2)
            if (s.find(num) != s.end()) {
                v.push_back(num);
                s.erase(num);
            }

        return v;
    }
};
