/*
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree
 *
 * Hard (32.48%)
 * Total Accepted:    55227
 * Total Submissions: 169950
 * Testcase Example:  '[]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment. 
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * 
 * For example, you may serialize the following tree
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * 
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 * 
 * Credits:Special thanks to @Louis1992 for adding this problem and creating
 * all test cases.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* p) {
        if (!p) return "#,";
        string s = to_string(p->val) + ",";
        s += serialize(p->left);
        s += serialize(p->right);
        return s;
    }

    vector<string> split(const string &s) {
        vector<string> v;
        size_t i = 0, j = 0, n = s.size();
        while (i < n) {
            j = s.find(',', i);
            if (j == string::npos) j = n;
            v.push_back(s.substr(i, j-i));
            i = j+1;
        }
        return v;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.empty() || s == "#,") return NULL;

        TreeNode *p, head(0);
        head.left = head.right = &head;

        stack<TreeNode*> st;
        st.push(&head);

        for (auto x : split(s)) {
            if (x != "#") {
                p = new TreeNode(stoi(x)); p->left = p->right = p;
                if (!st.empty()) {
                    TreeNode *p1 = st.top();
                    if (p1->left == p1) p1->left = p; else p1->right = p;
                }
                st.push(p);
            } else {
                p = st.top();
                if (p->left == p) p->left = NULL; else p->right = NULL;
                while (!st.empty() && st.top()->right != st.top()) st.pop();
            }
        }

        return head.left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
