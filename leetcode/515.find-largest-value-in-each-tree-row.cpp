/*
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row
 *
 * Medium (52.48%)
 * Total Accepted:    4091
 * Total Submissions: 7763
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if (!root) return v;

        queue<TreeNode*> q;
        q.push(root);
        int cur = 1, next = 0, x = numeric_limits<int>::min();

        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            x = max(x, p->val);
            if (p->left) { q.push(p->left); ++next; }
            if (p->right) { q.push(p->right); ++next; }

            if (--cur == 0) {
                v.push_back(x);
                x = numeric_limits<int>::min();
                swap(cur, next);
            }
        }

        return v;
    }
};
