/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 *
 * Medium (31.09%)
 * Total Accepted:    91271
 * Total Submissions: 293577
 * Testcase Example:  '[]\n[]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    vector<int> in, pre;

    TreeNode* next(int i1, int j1, int i2, int j2) {
        if (i1 > j1 || i2 > j2) return NULL;

        int x = pre[i1], k;
        for (k = i2; k <= j2 && in[k] != x; ++k);

        TreeNode* p = new TreeNode(x);
        p->left = next(i1+1, i1+k-i2, i2, k-1);
        p->right = next(j1+k+1-j2, j1, k+1, j2);
        return p;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder; in = inorder;
        if (pre.empty() || in.empty()) return NULL;

        return next(0, pre.size()-1, 0, in.size()-1);
    }
};
