/*
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree
 *
 * algorithms
 * Medium (72.74%)
 * Total Accepted:    7.2K
 * Total Submissions: 9.9K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
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
    vector<int> v;

    TreeNode* next(int i, int j) {
        if (i < 0 || i >= v.size() || i > j) return NULL;
        auto k = distance(v.begin(), max_element(v.begin()+i, v.begin()+j+1));
        TreeNode* p = new TreeNode(v[k]);
        p->left = next(i, k-1);
        p->right = next(k+1, j);
        return p;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        v = nums;
        return next(0, v.size()-1);
    }
};
