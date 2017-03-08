/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer
 *
 * Easy (44.19%)
 * Total Accepted:    133456
 * Total Submissions: 301987
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int romanToInt(string s) {
        int x = 0;

        int last = 0;
        for (auto c : s) {
            int cur = m[c];
            if (last < cur) x += cur-last-last;
            else x += cur;
            last = cur;
        }

        return x;
    }
};
