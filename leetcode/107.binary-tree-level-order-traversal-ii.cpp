/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii
 *
 * Easy (38.43%)
 * Total Accepted:    116354
 * Total Submissions: 302738
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 3
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * [15,7],
 * [9,20],
 * [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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

        reverse(vv.begin(), vv.end());
        return vv;
    }
};
