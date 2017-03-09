/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal
 *
 * Hard (38.93%)
 * Total Accepted:    131584
 * Total Submissions: 337804
 * Testcase Example:  '[]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if (!root) return v;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* p = s.top();
            s.pop();

            if (!p->left && !p->right) v.push_back(p->val);
            else { s.push(p); }

            if (p->right) { s.push(p->right); p->right = NULL; }
            if (p->left) { s.push(p->left); p->left = NULL; }
        }

        return v;
    }
};
