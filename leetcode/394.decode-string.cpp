/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string
 *
 * Medium (40.82%)
 * Total Accepted:    24766
 * Total Submissions: 60677
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums, braces;
        stack<string> strs;
        strs.push("");

        int num = 0;
        for (int i = 0, n = s.size(); i <= n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num*10+s[i]-'0';
            } else if (s[i] == '[') {
                nums.push(num); num = 0;
                braces.push(i);
                strs.push("");
            } else if (s[i] == ']') {
                braces.pop();
                string s = strs.top(); strs.pop();
                int count = nums.top(); nums.pop();

                while (count--) strs.top() += s;
            } else {
                strs.top().push_back(s[i]);
            }
        }

        return strs.top();
    }
};
