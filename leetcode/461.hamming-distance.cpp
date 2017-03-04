/*
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance
 *
 * Easy (70.93%)
 * Total Accepted:    37455
 * Total Submissions: 52796
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 &le; x, y &lt; 231.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        y = 0;
        while(x) { x &= x-1; ++y; }
        return y;
    }
};
