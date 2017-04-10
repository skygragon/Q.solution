/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list
 *
 * Medium (33.98%)
 * Total Accepted:    115851
 * Total Submissions: 340803
 * Testcase Example:  '[]'
 *
 * 
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * 
 * 
 * For example,
 * Given
 * 
 * ⁠        1
 * ⁠       / \
 * ⁠      2   5
 * ⁠     / \   \
 * ⁠    3   4   6
 * 
 * 
 * 
 * The flattened tree should look like:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠     \
 * ⁠      3
 * ⁠       \
 * ⁠        4
 * ⁠         \
 * ⁠          5
 * ⁠           \
 * ⁠            6
 * 
 * 
 * click to show hints.
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child
 * points to the next node of a pre-order traversal.
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        if (root) s.push(root);

        TreeNode* last = NULL;
        while (!s.empty()) {
            TreeNode* p = s.top(); s.pop();

            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);

            p->left = NULL;
            if (last) last->right = p;
            last = p;
        }
        if (last) last->right = NULL;
    }
};
