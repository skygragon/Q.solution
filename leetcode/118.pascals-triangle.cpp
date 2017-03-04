/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle
 *
 * Easy (37.18%)
 * Total Accepted:    118781
 * Total Submissions: 319449
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 * [1],
 * [1,1],
 * [1,2,1],
 * [1,3,3,1],
 * [1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vector<int> v = {};
        for (; numRows > 0; --numRows) {
            v.push_back(1);
            for (int i = v.size()-2; i >= 1; --i)
                v[i] += v[i-1];
            vv.push_back(v);
        }
        return vv;
    }
};
