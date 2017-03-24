/*
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
 *
 * Medium (35.55%)
 * Total Accepted:    31759
 * Total Submissions: 89344
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 * 
 * 
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * 
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * 
 * Given a string of comma separated values, verify whether it is a correct
 * preorder traversal serialization of a binary tree. Find an algorithm without
 * reconstructing the tree.
 * 
 * Each comma separated value in the string must be either an integer or a
 * character '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could
 * never contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Return true
 * Example 2:
 * "1,#"
 * Return false
 * Example 3:
 * "9,#,#,1"
 * Return false
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    vector<string> split(const string &s) {
        vector<string> v;
        int last = -1, n = s.size();
        while (true) {
            size_t pos = s.find(",", last+1);
            if (pos == string::npos) break;

            int cur = pos;
            v.push_back(s.substr(last+1, cur-last-1));
            last = cur;
        }
        v.push_back(s.substr(last+1, n-last-1));
        return v;
    }

    bool isValidSerialization(string preorder) {
        vector<string> v = split(preorder);
        int n = v.size();
        if (n == 0) return false;
        if (n == 1) return v[0] == "#";
        if (n > 1 && v[0] == "#") return false;

        stack<int> s;
        s.push(0);

        for (int i = 1; i < n; ++i) {
            if (s.empty()) return false;
            if (++s.top() > 2) return false;

            if (v[i] != "#") s.push(0);
            while (!s.empty() && s.top() == 2) s.pop();
        }

        return s.empty();
    }
};
