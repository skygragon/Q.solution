/*
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string
 *
 * Hard (24.10%)
 * Total Accepted:    65025
 * Total Submissions: 269871
 * Testcase Example:  '""\n""\n""'
 *
 * 
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * 
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 * 
 */
class Solution {
public:
    string s1, s2, s3;
    int n1, n2, n3;
    unordered_map<int, bool> m;

    bool next(int i, int j, int k) {
        int key = i*n2*n3+j*n3+k;
        if (m.find(key) != m.end()) return m[key];

        bool x = false;
        if (i == n1 && j == n2) x = (k == n3);
        else if (k == n3) x = (i == n1) && (j == n2);
        else {
            if (i < n1) x = (s1[i] == s3[k]) && next(i+1,j,k+1);
            if (!x && j < n2) x = (s2[j] == s3[k]) && next(i,j+1,k+1);
        }

        return m[key] = x;
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1; this->s2 = s2; this->s3 = s3;
        n1 = s1.size(); n2 = s2.size(); n3 = s3.size();

        return next(0, 0, 0);
    }
};
