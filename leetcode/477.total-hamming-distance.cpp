/*
 * [477] Total Hamming Distance
 *
 * https://leetcode.com/problems/total-hamming-distance
 *
 * Medium (45.91%)
 * Total Accepted:    10463
 * Total Submissions: 22742
 * Testcase Example:  '[4,14,2]'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Now your job is to find the total Hamming distance between all pairs of the
 * given numbers.
 * 
 * 
 * Example:
 * 
 * Input: 4, 14, 2
 * 
 * Output: 6
 * 
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
 * 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 * 
 * 
 * 
 * Note:
 * 
 * Elements of the given array are in the range of 0  to 10^9
 * Length of the array will not exceed 10^4. 
 * 
 * 
 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int x = 0, n = nums.size();
        vector<int> v(sizeof(int)*8, 0);

        for (auto num : nums) {
            for (int i = 0; i < v.size(); ++i) {
                v[i] += ((num & (1 << i)) >> i);
            }
        }

        for (auto num : v) x += num*(n-num);

        return x;
    }
};
