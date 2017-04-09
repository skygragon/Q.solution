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

        queue<TreeNode*> cur, next;
        if (root) cur.push(root);

        while (!cur.empty()) {
            vector<int> v;

            while (!cur.empty()) {
                TreeNode* p = cur.front(); cur.pop();
                v.push_back(p->val);

                if (p->left) next.push(p->left);
                if (p->right) next.push(p->right);
            }

            if (vv.size()%2) reverse(v.begin(),v.end());
            vv.push_back(v);
            swap(cur, next);
        }
        return vv;
    }
};
