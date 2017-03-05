/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7
 *
 * Easy (46.39%)
 * Total Accepted:    4848
 * Total Submissions: 10450
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7
 *
 * Easy (46.39%)
 * Total Accepted:    4848
 * Total Submissions: 10450
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
class Solution {
public:
    string convertToBase7(int num) {
       int n = num > 0 ? num : -num;
       string s;

       while (n > 0) {
          s = to_string(n % 7) + s;
          n /= 7;
       }

       if (s.empty()) s = "0";
       if (num < 0) s = "-" + s;

       return s;
    }
};

