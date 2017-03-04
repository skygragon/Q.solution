/*
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits
 *
 * Easy (50.47%)
 * Total Accepted:    151185
 * Total Submissions: 299531
 * Testcase Example:  '0'
 *
 * 
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit. 
 * 
 * 
 * 
 * For example:
 * 
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only
 * one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * 
 * 
 * A naive implementation of the above process is trivial. Could you come up
 * with other methods? 
 * What are all the possible results?
 * How do they occur, periodically or randomly?
 * You may find this Wikipedia article useful.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int addDigits(int num) {
        int x = num % 9;
        return (num == 0 || x) ? x : 9;
    }
};
