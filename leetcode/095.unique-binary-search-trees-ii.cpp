/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii
 *
 * Medium (30.77%)
 * Total Accepted:    75688
 * Total Submissions: 245958
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1...n.
 * 
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<vector<TreeNode*>> vv;

    TreeNode* copy(TreeNode *p, int dx) {
        if (!p) return NULL;
        TreeNode *p1 = new TreeNode(p->val + dx);
        p1->left = copy(p->left, dx);
        p1->right = copy(p->right, dx);
        return p1;
    }

    void next(int n) {
        if (n == 1) {
            vv[1].push_back(new TreeNode(1));
            return;
        }

        next(n-1);

        TreeNode *p = NULL, *p1 = NULL, *p2 = NULL;
        for (auto root : vv[n-1]) {
            p = new TreeNode(n);
            p->left = copy(root, 0);
            vv[n].push_back(p);

            p = new TreeNode(n);
            p1 = copy(root, 0);
            vv[n].push_back(p1);

            while (p1->right) p1 = p1->right;
            p1->right = p;
        }

        for (int i = 1; i < n-1; ++i) {
            int j = n-1-i;
            for (auto root_l : vv[i]) {
                for (auto root_r : vv[j]) {
                    p1 = copy(root_l, 0);
                    vv[n].push_back(p1);

                    p = new TreeNode(n);
                    p->left = copy(root_r, i);

                    while (p1->right) p1 = p1->right;
                    p1->right = p;
                }
            }
        }
    }

    vector<TreeNode*> generateTrees(int n) {
        vv.resize(n+1);
        if (n) next(n);

        return vv[n];
    }
};
