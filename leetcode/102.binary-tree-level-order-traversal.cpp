/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal
 *
 * Medium (37.80%)
 * Total Accepted:    156769
 * Total Submissions: 414383
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        vector<int> v;

        queue<TreeNode*> q;
        if (root) q.push(root);

        int cur = 1, next = 0;
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            v.push_back(p->val);

            if (p->left) { q.push(p->left); ++next; }
            if (p->right) { q.push(p->right); ++next; }

            if (--cur == 0) {
                vv.push_back(v);
                v.clear();
                swap(cur, next);
            }
        }

        return vv;
    }
};
