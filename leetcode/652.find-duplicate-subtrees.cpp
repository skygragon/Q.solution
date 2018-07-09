/*
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees
 *
 * algorithms
 * Medium (31.67%)
 * Total Accepted:    4.2K
 * Total Submissions: 13.1K
 * Testcase Example:  '[2,1,1]'
 *
 * 
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them. 
 * 
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * 
 * Example 1: 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * The following are two duplicate subtrees:
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * and
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
 * 
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
    vector<TreeNode*> v;
    unordered_map<string, int> m;

    string next(TreeNode* p) {
        if (!p) return "";
        string s = to_string(p->val) + "(" +
            next(p->left) + "," +
            next(p->right) + ")";

        if (m.find(s) != m.end()) {
            if (m[s] == 1) v.push_back(p);
            ++m[s];
        } else {
            m[s] = 1;
        }

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        next(root);
        return v;
    }
};
