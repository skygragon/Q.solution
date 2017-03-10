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
    void next(TreeNode* p, int cur, int& sum) {
        if (!p) return;
        cur = cur * 10 + p->val;
        if (!p->left && !p->right) sum += cur;

        next(p->left, cur, sum);
        next(p->right, cur, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        next(root, 0, sum);
        return sum;
    }
};
