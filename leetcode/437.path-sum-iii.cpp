/*
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii
 *
 * Easy (38.92%)
 * Total Accepted:    19730
 * Total Submissions: 50701
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    int target, count {0};
    vector<int> sums;

    void next(TreeNode* p) {
        if (!p) return;

        int cur = (sums.empty() ? 0 : sums.back()) + p->val;
        if (cur == target) ++count;
        for (auto sum : sums) {
            if (cur - sum == target) ++count;
        }

        sums.push_back(cur);
        next(p->left);
        next(p->right);
        sums.pop_back();
    }

    int pathSum(TreeNode* root, int sum) {
        target = sum;
        next(root);
        return count;
    }
};
