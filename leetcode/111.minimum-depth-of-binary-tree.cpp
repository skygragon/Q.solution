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
    int minDepth(TreeNode* p) {
        if (!p) return 0;
        if (!p->left && !p->right) return 1;

        int d = numeric_limits<int>::max();
        if (p->left) d = min(d, 1+minDepth(p->left));
        if (p->right) d = min(d, 1+minDepth(p->right));
        return d;
    }
};
