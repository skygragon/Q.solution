/*
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins
 *
 * Easy (35.95%)
 * Total Accepted:    19031
 * Total Submissions: 52906
 * Testcase Example:  '5'
 *
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * ⁠
 * Given n, find the total number of full staircase rows that can be formed.
 * 
 * n is a non-negative integer and fits within the range of a 32-bit signed
 * integer.
 * 
 * Example 1:
 * 
 * n = 5
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * Because the 3rd row is incomplete, we return 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * n = 8
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * Because the 4th row is incomplete, we return 3.
 * 
 * 
 */
class Solution {
public:
    int arrangeCoins(int n) {
        long long i = 1, j = sqrt(n) * 1.5;
        while (i <= j) {
            long long m = i+(j-i)/2;
            long long x = m*(m+1)/2;
            if (x == n) return m;
            else if (x > n) j = m-1;
            else i = m+1;
        }
        return j;
    }
};
