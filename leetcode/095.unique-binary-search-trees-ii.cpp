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
    vector<TreeNode*> next(int i, int j) {
        vector<TreeNode*> v;
        if (i > j) { v.push_back(NULL); return v; }

        for (int k = i; k <= j; ++k)
            for (auto l : next(i, k-1))
                for (auto r : next(k+1, j)) {
                    TreeNode *p = new TreeNode(k);
                    p->left = l; p->right = r;
                    v.push_back(p);
                }
        return v;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return next(1, n);
    }
};
