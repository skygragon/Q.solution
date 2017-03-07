/*
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst
 *
 * Easy (48.28%)
 * Total Accepted:    5105
 * Total Submissions: 10573
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * 
 * Example:
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note:
 * There are at least two nodes in this BST.
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
    TreeNode* last;
    int x;

    void inOrder(TreeNode* p) {
        if (!p) return;
        inOrder(p->left);
        if (last) x = min(x, p->val - last->val);
        last = p;
        inOrder(p->right);
    }

    int getMinimumDifference(TreeNode* root) {
        last = NULL;
        x = numeric_limits<int>::max();

        inOrder(root);
        return x;
    }
};
