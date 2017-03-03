/*
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list
 *
 * Medium (32.13%)
 * Total Accepted:    93658
 * Total Submissions: 291505
 * Testcase Example:  '[]'
 *
 * Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;

        ListNode node(0);

        ListNode* p = head;
        while (p) {
            ListNode* p1 = &node;
            while (p1->next && p1->next->val < p->val)
                p1 = p1->next;

            head = p->next;
            p->next = p1->next;
            p1->next = p;
            p = head;
        }

        return node.next;
    }
};
