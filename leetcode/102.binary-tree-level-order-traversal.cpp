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

        queue<TreeNode*> cur, next;
        if (root) cur.push(root);

        while (!cur.empty()) {
            vector<int> v;

            while (!cur.empty()) {
                TreeNode* p = cur.front(); cur.pop();
                v.push_back(p->val);

                if (p->left) next.push(p->left);
                if (p->right) next.push(p->right);
            }

            vv.push_back(v);
            swap(cur, next);
        }
        return vv;
    }
};
