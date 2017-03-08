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
    vector<int> v;
    int sum;

    void next(TreeNode* p, int x) {
        if (!p) return;

        v.push_back(p->val);
        x += p->val;

        if (!p->left && !p->right && x == sum) {
            vv.push_back(v);
        } else {
            next(p->left, x);
            next(p->right, x);
        }
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        this->sum = sum;
        next(root, 0);
        return vv;
    }
};
