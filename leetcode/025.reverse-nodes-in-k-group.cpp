/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group
 *
 * Hard (30.02%)
 * Total Accepted:    84984
 * Total Submissions: 283060
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * 
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be
 * changed.
 * 
 * Only constant memory is allowed.
 * 
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * 
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * 
 * 
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;

        int n = 0;
        ListNode *p = head;
        while (p) { ++n; p = p->next; }

        if (n < k) return head;

        ListNode node(0), *cur = &node;
        p = head;
        while (n >= k) {
            ListNode *end = p;
            for (int i = 0; i < k; ++i) {
                ListNode* next = p->next;
                p->next = cur->next; cur->next = p;
                p = next;
            }
            cur = end;
            n -= k;
        }
        cur->next = p;

        return node.next;
    }
};
