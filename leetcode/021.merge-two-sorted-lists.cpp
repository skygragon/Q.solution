/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 *
 * Easy (38.31%)
 * Total Accepted:    197977
 * Total Submissions: 516795
 * Testcase Example:  '[]\n[]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode node(0);
        ListNode* p = &node;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1; l1 = l1->next; p = p->next;
            } else {
                p->next = l2; l2 = l2->next; p = p->next;
            }
        }
        while (l1) { p->next = l1; l1 = l1->next; p = p->next; }
        while (l2) { p->next = l2; l2 = l2->next; p = p->next; }

        return node.next;
    }
};
