/*
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz
 *
 * Easy (58.50%)
 * Total Accepted:    47773
 * Total Submissions: 81636
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * "1",
 * "2",
 * "Fizz",
 * "4",
 * "Buzz",
 * "Fizz",
 * "7",
 * "8",
 * "Fizz",
 * "Buzz",
 * "11",
 * "Fizz",
 * "13",
 * "14",
 * "FizzBuzz"
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) v[i-1] = "FizzBuzz";
            else if (i % 5 == 0) v[i-1] = "Buzz";
            else if (i % 3 == 0) v[i-1] = "Fizz";
            else v[i-1] = to_string(i);
        }

        return v;
    }
};
