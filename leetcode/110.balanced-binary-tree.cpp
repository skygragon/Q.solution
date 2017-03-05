/*
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree
 *
 * Easy (36.50%)
 * Total Accepted:    158401
 * Total Submissions: 433943
 * Testcase Example:  '[]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * 
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
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
    int find(TreeNode* p) {
        if (!p) return 0;

        int x = find(p->left);
        if (x < 0) return x;

        int y = find(p->right);
        if (y < 0) return y;

        if (x < y) swap(x, y);

        return x-y > 1 ? y-x : x+1;
    }

    bool isBalanced(TreeNode* root) {
        return find(root) >= 0;
    }
};
