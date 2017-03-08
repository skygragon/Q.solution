/*
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes
 *
 * Medium (27.06%)
 * Total Accepted:    55358
 * Total Submissions: 204552
 * Testcase Example:  '[]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int complete(int h) { return (1 << h) - 1; }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode *p;

        int l = 0; p = root;
        while (p) { p = p->left; ++l; }
        int r = 0; p = root;
        while (p) { p = p->right; ++r; }

        if (l == r) return complete(l);

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
