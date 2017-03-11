/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree
 *
 * Easy (39.46%)
 * Total Accepted:    8038
 * Total Submissions: 20359
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * return [2].
 * 
 * 
 * Note:
 * If a tree has more than one mode, you can return them in any order.
 * 
 * 
 * Follow up:
 * Could you do that without using any extra space? (Assume that the implicit
 * stack space incurred due to recursion does not count).
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
    vector<int> v;
    int maxCount {0}, count {0};
    TreeNode* last;

    void checkMax() {
        if (!last) return;
        if (count < maxCount) return;
        if (count > maxCount) {
            v.clear();
            maxCount = count;
        }
        v.push_back(last->val);
    }

    void next(TreeNode* p) {
        if (!p) return;

        next(p->left);
        if (!last || p->val != last->val) {
            checkMax();
            last = p;
            count = 1;
        } else {
            ++count;
        }
        next(p->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        next(root);
        checkMax();

        return v;
    }
};
