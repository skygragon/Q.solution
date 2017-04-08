/*
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list
 *
 * Medium (24.14%)
 * Total Accepted:    97963
 * Total Submissions: 405844
 * Testcase Example:  '[]\n0'
 *
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head, *p1 = NULL;
        while (p) { ++n; p = p->next; }
        if (n == 0) return head;

        k %= n;
        if (k == 0) return head;

        p = head;
        while (--n > k) p = p->next;
        p1 = p->next; p->next = NULL;

        p = p1;
        while (p->next) p = p->next;
        p->next = head;

        return p1;
    }
};
