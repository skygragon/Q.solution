/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii
 *
 * Easy (35.51%)
 * Total Accepted:    105220
 * Total Submissions: 296311
 * Testcase Example:  '0'
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * 
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        while (rowIndex-- >= 0) {
            v.push_back(1);
            for (int i = v.size()-2; i >= 1; --i) v[i] += v[i-1];
        }
        return v;
    }
};
