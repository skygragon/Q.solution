/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 * Easy (39.13%)
 * Total Accepted:    166030
 * Total Submissions: 424281
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode node(0);
        ListNode* p = &node;

        while (head) {
            if (p == &node || p->val != head->val) {
                p->next = head;
                p = p->next;
                head = head->next;
            } else {
                ListNode* p1 = head;
                head = head->next;
                delete(p1);
            }
        }
        p->next = NULL;

        return node.next;
    }
};
