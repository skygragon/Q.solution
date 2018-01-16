/*
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (46.98%)
 * Total Accepted:    13K
 * Total Submissions: 27.7K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * 
 * 
 * 
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * 
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int num = nums[i];
            if (m.find(num) == m.end()) m[num] = {0, i, 0};

            // count, first index, length
            vector<int> &v = m[num];
            ++v[0]; v[2] = i - v[1] + 1;
        }

        int n = 0, len = numeric_limits<int>::max();
        for (auto p: m) { 
            if (p.second[0] > n) {
                n = p.second[0];
                len = p.second[2];
            } else if (p.second[0] == n) {
                len = min(len, p.second[2]);
            }
        }
        return len;
    }
};

