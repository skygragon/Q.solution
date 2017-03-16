/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path
 *
 * Medium (24.46%)
 * Total Accepted:    78660
 * Total Submissions: 321555
 * Testcase Example:  '"/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public:
    vector<string> split(const string &s) {
        vector<string> v;
        for(int i = 0, last = -1, n = s.size(); i <= n; ++i) {
            if (s[i] == '/' || i == n) {
                int len = i-last-1;
                if (len > 0) v.push_back(s.substr(last+1, len));
                last = i;
            }
        }
        return v;
    }

    string simplifyPath(string path) {
        vector<string> v = split(path);
        stack<string> st;
        for (auto &s : v) {
            if (s == "..") {
                if (!st.empty()) st.pop();
            } else if (s == ".") continue;
            else st.push(s);
        }

        string path2;
        while (!st.empty()) {
            path2 = "/" + st.top() + path2;
            st.pop();
        }
        if (path2.empty()) path2 = "/";

        return path2;
    }
};
