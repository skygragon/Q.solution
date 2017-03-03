/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii
 *
 * Medium (29.97%)
 * Total Accepted:    99745
 * Total Submissions: 332767
 * Testcase Example:  '[5]\n1\n1'
 *
 * 
 * Reverse a linked list from position m to n. Do it in-place and in
 * one-pass.
 * 
 * 
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;

        ListNode node(0);
        node.next = head;

        ListNode* p = &node;
        int i = 0;

        while (++i <= m) {
            head = p;
            p = p->next;
        }

        ListNode* p1 = p->next;
        while (i++ <= n) {
            p->next = p1->next;
            p1->next = head->next;
            head->next = p1;
            p1 = p->next;
        }

        return node.next;
    }
};
