/*
 * [804] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (50.77%)
 * Total Accepted:    3.7K
 * Total Submissions: 7.3K
 * Testcase Example:  '10'
 *
 * X is a good number if after rotating each digit individually by 180 degrees,
 * we get a valid number that is different from X. A number is valid if each
 * digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2
 * and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of
 * the numbers do not rotate to any other number.
 * 
 * Now given a positive number N, how many numbers X from 1 to N are good?
 * 
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: 
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N  will be in range [1, 10000].
 * 
 */
class Solution {
public:
    int rotated[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

    int check(int x) {
        int ok = 0;
        while (x) {
            int y = x % 10; x = x / 10;
            if (rotated[y] < 0) return 0;
            if (rotated[y] != y) ok = 1;
        }
        return ok;
    }

    int rotatedDigits(int N) {
        int cnt = 0;
        for (int i = 2; i <= N; ++i) cnt += check(i);
        return cnt;
    }
};
