/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list
 *
 * Medium (31.77%)
 * Total Accepted:    90787
 * Total Submissions: 285800
 * Testcase Example:  '[]\n0'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode h1(0), h2(0);
        ListNode* p = head, *p1 = &h1, *p2 = &h2;
        while (p) {
            if (p->val < x) {
                p1->next = p; p1 = p1->next;
            } else {
                p2->next = p; p2 = p2->next;
            }
            p = p->next;
        }

        p1->next = h2.next;
        p2->next = NULL;
        return h1.next;
    }
};
