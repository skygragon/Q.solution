/*
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list
 *
 * Medium (24.85%)
 * Total Accepted:    85419
 * Total Submissions: 343733
 * Testcase Example:  '[]'
 *
 * 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 * 
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode node(0);
        ListNode *p = NULL, *p1 = head, *p2 = head;
        while (p2) {
            p = p1;
            p1 = p1->next;
            p2 = p2->next; if (!p2) break; p2 = p2->next;
        }

        p->next = NULL;
        while (p1) {
            p2 = p1->next;
            p1->next = node.next;
            node.next = p1;
            p1 = p2;
        }

        p1 = head; p2 = node.next;
        while (p1 && p2) {
            p = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next->next;
            p2 = p;
        }
    }
};
