/*
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication
 *
 * Medium (66.17%)
 * Total Accepted:    2582
 * Total Submissions: 3907
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 
 * Given two strings representing two complex numbers.
 * 
 * 
 * You need to return a string representing their multiplication. Note i2 = -1
 * according to the definition.
 * 
 * 
 * Example 1:
 * 
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 * 
 * 
 * 
 * Note:
 * 
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 * 
 * 
 */
class Solution {
public:
    using P = pair<int, int>;

    P parse(const string &s) {
        auto i = s.find('+');
        auto j = s.find('i');
        return {stoi(s.substr(0, i)), stoi(s.substr(i+1, j-i-1))};
    }

    string complexNumberMultiply(string a, string b) {
        auto p1 = parse(a);
        auto p2 = parse(b);
        int x = p1.first * p2.first - p1.second * p2.second;
        int y = p1.first * p2.second + p1.second * p2.first;
        return to_string(x) + "+" + to_string(y) + "i";
    }
};
