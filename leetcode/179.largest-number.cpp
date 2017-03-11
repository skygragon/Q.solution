/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number
 *
 * Medium (21.74%)
 * Total Accepted:    67020
 * Total Submissions: 308241
 * Testcase Example:  '[1]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp = [](const string &s1, const string &s2) {
            return s1+s2 > s2+s1;
        };
        multiset<string, decltype(comp)> s(comp);
        for (auto num : nums) s.insert(to_string(num));


        string x;
        x = accumulate(s.begin(), s.end(), x,
                [](const string &sum, const string &x) { return sum + x; });

        while (!x.empty() && x[0] == '0') x.erase(0, 1);
        if (x.empty()) x = "0";

        return x;
    }
};
