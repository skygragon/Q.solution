/*
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits
 *
 * Medium (60.12%)
 * Total Accepted:    69210
 * Total Submissions: 115148
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * 
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 * 
 * 
 * Follow up:
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount  in c++ or in any other language.
 * 
 * 
 * 
 * 
 * ⁠ You should make use of what you have produced already.
 * ⁠ Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try
 * to generate new range from previous.
 * ⁠ Or does the odd/even status of the number help you in calculating the
 * number of 1s?
 * 
 * 
 * Credits:Special thanks to @ syedee  for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1, 0);

        int b = 0, e = 1;
        for (int i = 1; i <= n; ++i) {
            if (i < e) v[i] = v[i-b]+1;
            else if (i == e) {
                v[i] = 1;
                b = e; e = e << 1;
            }
        }

        return v;
    }
};
