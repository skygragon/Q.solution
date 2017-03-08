/*
 * [423] Reconstruct Original Digits from English
 *
 * https://leetcode.com/problems/reconstruct-original-digits-from-english
 *
 * Medium (42.97%)
 * Total Accepted:    7744
 * Total Submissions: 18035
 * Testcase Example:  '"owoztneoer"'
 *
 * Given a non-empty string containing an out-of-order English representation
 * of digits 0-9, output the digits in ascending order.
 * 
 * Note:
 * 
 * Input contains only lowercase English letters.
 * Input is guaranteed to be valid and can be transformed to its original
 * digits. That means invalid inputs such as "abc" or "zerone" are not
 * permitted.
 * Input length is less than 50,000.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "owoztneoer"
 * 
 * Output: "012"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "fviefuro"
 * 
 * Output: "45"
 * 
 * 
 */
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> m;
        for (auto c : s) ++m[c];

        vector<int> v(10);
        v[0] = m['z'];
        v[2] = m['w']; m['t'] -= v[2];
        v[4] = m['u'];
        v[6] = m['x']; m['s'] -= v[6]; m['i'] -= v[6];
        v[8] = m['g']; m['t'] -= v[8]; m['i'] -= v[8];
        v[7] = m['s']; m['v'] -= v[7]; m['n'] -= v[7];
        v[5] = m['v']; m['i'] -= v[5];
        v[3] = m['t'];
        v[9] = m['i']; m['n'] -= v[9]*2;
        v[1] = m['n'];

        string str;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < v[i]; ++j) str.push_back('0' + i);
        }

        return str;
    }
};
