/*
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
 *
 * Medium (29.56%)
 * Total Accepted:    91624
 * Total Submissions: 309952
 * Testcase Example:  '[1,2]\nnode with value 1\nnode with value 2'
 *
 * 
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 * 
 * 
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of
 * itself).”
 * 
 * 
 * 
 * ⁠       _______3______
 * ⁠      /              \
 * ⁠   ___5__          ___1__
 * ⁠  /      \        /      \
 * ⁠  6      _2       0       8
 * ⁠        /  \
 * ⁠        7   4
 * 
 * 
 * 
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another
 * example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of
 * itself according to the LCA definition.
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
    TreeNode *parent, *p, *q;
    vector<TreeNode*> cur, last;

    void next(TreeNode *node) {
        if (!node) return;
        if (parent) return;

        cur.push_back(node);
        if (node == p || node == q) {
            if (!last.empty()) {
                int i = 0;
                while (i < cur.size() && i < last.size() && cur[i] == last[i]) ++i;
                parent = cur[i-1];
                return;
            } else {
                last = cur;
            }
        }

        next(node->left);
        next(node->right);
        cur.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        next(root);
        return parent;
    }
};
