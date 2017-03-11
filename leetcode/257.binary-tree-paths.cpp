/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths
 *
 * Easy (36.01%)
 * Total Accepted:    94910
 * Total Submissions: 263527
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * 
 * For example, given the following binary tree:
 * 
 * 
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
    vector<string> vs;

    void next(TreeNode* p, const string &s) {
        if (!p) return;

        const string s1 = s + "->" + to_string(p->val);

        if (!p->left && !p->right) {
            vs.push_back(s1.substr(2));
            return;
        }

        next(p->left, s1);
        next(p->right, s1);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        next(root, "");
        return vs;
    }
};
