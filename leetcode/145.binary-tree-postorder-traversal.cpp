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
        stack<TreeNode*> s;
        while (root) { s.push(root); root = root->left; }

        TreeNode *last = NULL;
        while (!s.empty()) {
            TreeNode* p = s.top();
            if (!p->right || p->right == last) {
                v.push_back(p->val);
                s.pop();
                last = p;
            } else {
                p = p->right;
                while (p) { s.push(p); p = p->left; }
            }
        }
        return v;
    }
};
