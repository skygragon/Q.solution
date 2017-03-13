/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways
 *
 * Medium (19.12%)
 * Total Accepted:    109062
 * Total Submissions: 569603
 * Testcase Example:  '""'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 * 
 * 
 * 
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * 
 * The number of ways decoding "12" is 2.
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return n;

        vector<int> v(n+1, 0);
        v[n] = 1;

        for (int i = n-1; i >= 0; --i) {
            if (s[i] != '0') v[i] += v[i+1];
            if (i < n-1) {
                if (s[i] == '1') v[i] += v[i+2];
                if (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6') v[i] += v[i+2];
            }
        }

        return v[0];
    }
};
