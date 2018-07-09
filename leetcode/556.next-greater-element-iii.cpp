/*
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii
 *
 * algorithms
 * Medium (28.53%)
 * Total Accepted:    7.2K
 * Total Submissions: 25.1K
 * Testcase Example:  '12'
 *
 * 
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 * 
 * Example 1:
 * 
 * Input: 12
 * Output: 21
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 21
 * Output: -1
 * 
 * 
 */
class Solution {
public:
    int nextGreaterElement(int x) {
        string s = to_string(x);
        int n = s.size(), i, j;

        for (j = n-1; j > 0 && s[j] <= s[j-1]; --j);
        if (j == 0) return -1;

        i = j-1;
        for (; j < n && s[j] > s[i]; ++j);
        swap(s[i], s[j-1]);

        for (++i, j = n-1; i < j; ++i, --j) swap(s[i], s[j]);

        if (s.size() >= 10 && s > "2147483647") return -1;
        if (s == to_string(x)) return -1;

        return stoi(s);
    }
};
