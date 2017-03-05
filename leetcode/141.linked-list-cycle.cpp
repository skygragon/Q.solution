/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle
 *
 * Easy (35.66%)
 * Total Accepted:    161754
 * Total Submissions: 453708
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
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
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* p1 = head;
        while (p && p1) {
            p = p->next;
            p1 = p1->next;
            if (!p1) return false;
            p1 = p1->next;
            if (p == p1) return true;
        }
        return false;
    }
};
