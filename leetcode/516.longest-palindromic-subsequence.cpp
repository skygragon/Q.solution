/*
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence
 *
 * Medium (40.67%)
 * Total Accepted:    1765
 * Total Submissions: 4338
 * Testcase Example:  '"bbbab"'
 *
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * "bbbab"
 * 
 * Output: 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 */
/*
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence
 *
 * Medium (40.67%)
 * Total Accepted:    1765
 * Total Submissions: 4338
 * Testcase Example:  '"bbbab"'
 *
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * "bbbab"
 * 
 * Output: 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 */
class Solution {
public:
    string s;
    int n;
    vector<int> cache;

    int find(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;

        int k = i*n+j;
        if (cache[k] >= 0) return cache[k];

        int x = (s[i] == s[j]) ? 2+find(i+1, j-1)
                               : max(find(i, j-1), find(i+1, j));

        return cache[k] = x;
    }

    int longestPalindromeSubseq(string s) {
        this->s = s;
        n = s.size();
        cache.resize(n*n, -1);
        return find(0, n-1);
    }
};

