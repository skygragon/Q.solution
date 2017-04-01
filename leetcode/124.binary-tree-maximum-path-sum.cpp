/*
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum
 *
 * Hard (25.29%)
 * Total Accepted:    88371
 * Total Submissions: 349329
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a binary tree, find the maximum path sum.
 * 
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * 
 * For example:
 * Given the below binary tree,
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 
 * 
 * Return 6.
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
    int x;

    int next(TreeNode *p) {
        if (!p) return 0;
        int l = next(p->left);
        int r = next(p->right);

        int y = max(l, r);
        if (y > 0) x = max(x, y);
        x = max(x, l+r+p->val);

        y = max(p->val, p->val + y);
        x = max(x, y);

        return y;
    }

    int maxPathSum(TreeNode* root) {
        x = numeric_limits<int>::min();
        next(root);
        return x;
    }
};
