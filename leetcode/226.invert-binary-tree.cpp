/*
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree
 *
 * Easy (50.39%)
 * Total Accepted:    155323
 * Total Submissions: 308252
 * Testcase Example:  '[]'
 *
 * Invert a binary tree.
 * 4
 * /   \
 * 2     7
 * / \   / \
 * 1   3 6   9
 * 
 * to
 * 4
 * /   \
 * 7     2
 * / \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so fuck off.
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
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);

            invertTree(root->left);
            invertTree(root->right);
        }

        return root;
    }
};
