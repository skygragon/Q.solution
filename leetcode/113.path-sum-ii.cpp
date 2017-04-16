/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii
 *
 * Medium (32.09%)
 * Total Accepted:    115991
 * Total Submissions: 361278
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 
 * return
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int>> vv;
    vector<int> cur;

    void next(TreeNode *p, int sum) {
        if (!p) return;

        cur.push_back(p->val); sum -= p->val;
        if (!p->left && !p->right && sum == 0) {
            vv.push_back(cur);
        } else {
            next(p->left, sum);
            next(p->right, sum);
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        next(root, sum);
        return vv;
    }
};
