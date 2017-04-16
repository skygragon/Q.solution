/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
 *
 * Easy (40.89%)
 * Total Accepted:    109611
 * Total Submissions: 268020
 * Testcase Example:  '[]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
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
    TreeNode* next(vector<int> &nums, int i, int j) {
        if (i > j) return NULL;
        int m = i+(j-i)/2;
        TreeNode *p = new TreeNode(nums[m]);
        p->left = next(nums, i, m-1);
        p->right = next(nums, m+1, j);
        return p;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return next(nums, 0, nums.size()-1);
    }
};
