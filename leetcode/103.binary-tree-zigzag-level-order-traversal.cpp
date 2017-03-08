/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
 *
 * Medium (31.83%)
 * Total Accepted:    81382
 * Total Submissions: 255663
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if (!root) return vv;

        queue<TreeNode*> q;
        q.push(root);
        int cur = 1, next = 0;
        vector<int> v;

        bool isReverse = false;
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            if (p->left) { q.push(p->left); ++next; }
            if (p->right) { q.push(p->right); ++next; }

            v.push_back(p->val);

            if (--cur == 0) {
                if (isReverse) reverse(v.begin(),v.end());
                isReverse = !isReverse;
                vv.push_back(v);
                v.clear();
                swap(cur, next);
            }
        }

        return vv;
    }
};
