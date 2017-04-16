/*
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers
 *
 * Medium (35.53%)
 * Total Accepted:    102596
 * Total Submissions: 288753
 * Testcase Example:  '[]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * For example,
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 
 * 
 * 
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * 
 * 
 * Return the sum = 12 + 13 = 25.
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
    int next(TreeNode *p, int cur) {
        if (!p) return 0;
        cur = cur*10 + p->val;
        if (!p->left && !p->right) return cur;
        return next(p->left, cur) + next(p->right, cur);
    }

    int sumNumbers(TreeNode* root) {
        return next(root, 0);
    }
};
