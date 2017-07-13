/*
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree
 *
 * Easy (61.15%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> cur, next;
        if (root) cur.push(root);

        vector<double> v;
        long long sum = 0, n = 0;
        while (!cur.empty()) {
            auto p = cur.front(); cur.pop();
            sum += p->val; ++n;
            if (p->left) next.push(p->left);
            if (p->right) next.push(p->right);

            if (cur.empty()) {
                v.push_back(sum*1.0/n);
                sum = n = 0;
                cur.swap(next);
            }
        }
        return v;
    }
};
