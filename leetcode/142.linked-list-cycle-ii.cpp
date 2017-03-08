/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii
 *
 * Medium (31.02%)
 * Total Accepted:    104626
 * Total Submissions: 337296
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *p1 = head;
        while (p && p1) {
            p = p->next; p1 = p1->next;
            if (!p || !p1) return NULL;
            p1 = p1->next;

            // found circle
            if (p == p1) {
                p1 = head;
                while (p != p1) { p = p->next; p1 = p1->next; }
                return p;
            }
        }
        return NULL;
    }
};
