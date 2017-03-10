/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers
 *
 * Medium (26.78%)
 * Total Accepted:    253942
 * Total Submissions: 948099
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode node(0); ListNode* p = &node;
        int x = 0;
        while (l1 || l2 || x) {
            if (l1) { x += l1->val; l1 = l1->next; }
            if (l2) { x += l2->val; l2 = l2->next; }

            ListNode* p1 = new ListNode(x % 10);
            p->next = p1; p = p1;

            x /= 10;
        }

        return node.next;
    }
};
