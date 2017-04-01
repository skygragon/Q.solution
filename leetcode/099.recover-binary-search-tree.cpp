/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree
 *
 * Hard (29.02%)
 * Total Accepted:    68060
 * Total Submissions: 234501
 * Testcase Example:  '[0,1]'
 *
 * 
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * 
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
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
    TreeNode *p1, *p2, *last;

    void next(TreeNode* p) {
        if (!p) return;

        next(p->left);

        if (last && p->val < last->val) {
            if (!p1) p1 = last;
            p2 = p;
        }
        last = p;

        next(p->right);
    }

    void recoverTree(TreeNode* root) {
        next(root);
        swap(p1->val, p2->val);
    }
};
