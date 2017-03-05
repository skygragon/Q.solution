/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum
 *
 * Easy (33.23%)
 * Total Accepted:    147807
 * Total Submissions: 444818
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * 5
 * / \
 * 4   8
 * /   / \
 * 11  13  4
 * /  \      \
 * 7    2      1
 * 
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool find(TreeNode* p, int x, int sum) {
        if (!p) return false;
        x += p->val;
        if (!p->left && !p->right) return x == sum;
        return find(p->left, x, sum) || find(p->right, x, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return find(root, 0, sum);
    }
};
