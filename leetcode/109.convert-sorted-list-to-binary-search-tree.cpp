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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;

        ListNode *p = head, *p1 = head, *last = NULL;
        while (p && p1) {
            p1 = p1->next; if (!p1) break; p1 = p1->next;
            last = p; p = p->next;
        }

        TreeNode* t = new TreeNode(p->val);
        if (last) {
            last->next = NULL;
            t->left = sortedListToBST(head);
        }
        t->right = sortedListToBST(p->next);

        return t;
    }
};
