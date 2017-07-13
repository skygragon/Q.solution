/*
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers
 *
 * Easy (45.24%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> M(3, numeric_limits<int>::min()), m(3, numeric_limits<int>::max());

        for (auto num: nums) {
            if (M[1] > -2000) {
                M[2] = max(M[2], max(M[1]*num, m[1]*num));
                m[2] = min(m[2], min(M[1]*num, m[1]*num));
            }
            if (M[0] > -2000) {
                M[1] = max(M[1], max(M[0]*num, m[0]*num));
                m[1] = min(m[1], min(M[0]*num, m[0]*num));
            }

            M[0] = max(M[0], num);
            m[0] = min(m[0], num);
        }

        return M[2];
    }
};
