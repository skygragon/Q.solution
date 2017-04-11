/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 *
 * Medium (31.22%)
 * Total Accepted:    77244
 * Total Submissions: 247445
 * Testcase Example:  '[]\n[]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    vector<int> in, post;

    TreeNode* next(int i1, int j1, int i2, int j2) {
        if (i1 > j1 || i2 > j2) return NULL;

        int x = post[j2], k;
        for (k = i1; k <= j1 && in[k] != x; ++k);

        TreeNode* p = new TreeNode(x);
        p->left = next(i1, k-1, i2, i2+k-1-i1);
        p->right = next(k+1, j1, j2+k-j1, j2-1);
        return p;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return NULL;

        in = inorder; post = postorder;
        return next(0, in.size()-1, 0, post.size()-1);
    }
};
