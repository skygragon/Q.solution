/*
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
 *
 * Medium (33.06%)
 * Total Accepted:    96751
 * Total Submissions: 292657
 * Testcase Example:  '[]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* next(ListNode *&p, int i, int j) {
        if (i > j) return NULL;

        int m = i+(j-i)/2;
        TreeNode *l = next(p, i, m-1);
        TreeNode *cur = new TreeNode(p->val); p = p->next;
        cur->left = l;
        cur->right = next(p, m+1, j);

        return cur;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0; ListNode *p = head;
        while (p) { p = p->next; ++n; }

        return next(head, 1, n);
    }
};
