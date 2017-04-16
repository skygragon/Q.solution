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

        ListNode node(0), *cur = head;
        while (cur) {
            ListNode *p = &node;
            while (p->next && p->next->val < cur->val) p = p->next;

            ListNode *tmp = cur->next;
            cur->next = p->next; p->next = cur;
            cur = tmp;
        }
        return node.next;
    }
};
