/*
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower
 *
 * Easy (34.06%)
 * Total Accepted:    39359
 * Total Submissions: 115581
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows: 
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 * 
 * -1 : My number is lower
 * 1 : My number is higher
 * 0 : Congrats! You got it!
 * 
 * 
 * Example:
 * 
 * n = 10, I pick 6.
 * 
 * Return 6.
 * 
 * 
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n, x;
        while (i <= j) {
            x = i + (j-i)/2;
            switch(guess(x)) {
                case 0: return x;
                case 1: i = x+1; break;
                case -1: j = x-1; break;
            }
        }
        return x;
    }
};
