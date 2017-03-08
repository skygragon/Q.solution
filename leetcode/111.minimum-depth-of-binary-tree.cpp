/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree
 *
 * Easy (32.50%)
 * Total Accepted:    151918
 * Total Submissions: 467346
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
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
    int x = numeric_limits<int>::max();

    void next(TreeNode* p, int d) {
        if (!p->left && !p->right) {
            x = min(x, d);
            return;
        }
        if (p->left) next(p->left, d+1);
        if (p->right) next(p->right, d+1);
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        next(root, 1);
        return x;
    }
};
