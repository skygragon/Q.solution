/*
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves
 *
 * Easy (46.22%)
 * Total Accepted:    38954
 * Total Submissions: 84257
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * 3
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
 * 
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
    int find(TreeNode* p, bool isLeft) {
        if (!p) return 0;
        if (!p->left && !p->right)
            return isLeft ? p->val : 0;
        return find(p->left, true) + find(p->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return find(root, false);
    }
};
