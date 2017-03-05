/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list
 *
 * Easy (44.11%)
 * Total Accepted:    197504
 * Total Submissions: 447726
 * Testcase Example:  '[]'
 *
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode node(0);
        ListNode* p = head;
        head = &node;

        while (p) {
            ListNode* p1 = p->next;

            p->next = head->next;
            head->next = p;

            p = p1;
        }

        return node.next;
    }
};
