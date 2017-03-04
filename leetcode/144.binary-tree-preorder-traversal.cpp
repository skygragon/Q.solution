/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal
 *
 * Medium (43.60%)
 * Total Accepted:    165800
 * Total Submissions: 380295
 * Testcase Example:  '[]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 * 1
 * \
 * 2
 * /
 * 3
 * 
 * 
 * 
 * return [1,2,3].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (!root) return v;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            v.push_back(p->val);

            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }

        return v;
    }
};
