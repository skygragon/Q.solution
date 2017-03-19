/*
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning
 *
 * Medium (31.41%)
 * Total Accepted:    87699
 * Total Submissions: 279197
 * Testcase Example:  '"aab"'
 *
 * 
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * 
 * For example, given s = "aab",
 * 
 * Return
 * 
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> vv;
    vector<string> cur;
    vector<vector<bool>> p;
    string s;
    int n;

    void next(int i) {
        if (i == n) { vv.push_back(cur); return; }

        for (int j = i; j < n; ++j) {
            if (!p[i][j]) continue;
            cur.push_back(s.substr(i, j-i+1));
            next(j+1);
            cur.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.size();

        p.resize(n);
        for (auto &row : p) row.resize(n, false);

        for (int i = 0; i < n; ++i) p[i][i] = true;
        for (int i = n-1; i >= 0; --i)
            for (int j = i+1; j < n; ++j) {
                p[i][j] = s[i] == s[j];
                if (i+1 < j) p[i][j] = p[i][j] && p[i+1][j-1];
            }

        next(0);

        return vv;
    }
};
