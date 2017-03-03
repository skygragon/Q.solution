/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one
 *
 * Easy (37.40%)
 * Total Accepted:    152920
 * Total Submissions: 408892
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int x = 1;
        for (int i = digits.size() - 1; i >= 0 && x > 0; --i) {
            x += digits[i];
            digits[i] = x % 10;
            x /= 10;
        }
        if (x) digits.insert(digits.begin(), x);
        return digits;
    }
};
