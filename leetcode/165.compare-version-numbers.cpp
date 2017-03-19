/*
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers
 *
 * Medium (19.53%)
 * Total Accepted:    79387
 * Total Submissions: 406455
 * Testcase Example:  '"1"\n"0"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise
 * return 0.
 * 
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 * 
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    vector<int> split(const string &s) {
        vector<int> v;
        for (int i = 0, last = -1, n = s.size(); i <= n; ++i) {
            if (i == n || s[i] == '.') {
                v.push_back(stoi(s.substr(last+1, i-last-1)));
                last = i;
            }
        }
        int i = v.size()-1;
        while (i > 0 && v[i] == 0) --i;
        v.resize(i+1);

        return v;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);

        return v1 == v2 ? 0 : (v1 < v2 ? -1 : 1);
    }
};
