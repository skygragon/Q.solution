/*
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view
 *
 * Medium (39.37%)
 * Total Accepted:    72100
 * Total Submissions: 182828
 * Testcase Example:  '[]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * 
 * For example:
 * Given the following binary tree,
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 * 
 * 
 * You should return [1, 3, 4].
 * 
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;

        queue<TreeNode*> q;
        if (root) q.push(root);
        int cur = 1, next = 0;

        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            if (p->left) { q.push(p->left); ++next; }
            if (p->right) { q.push(p->right); ++next; }

            if (cur == 1) v.push_back(p->val);
            if (--cur == 0) swap(cur, next);
        }

        return v;
    }
};
