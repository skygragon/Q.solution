/*
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list
 *
 * Medium (42.34%)
 * Total Accepted:    59142
 * Total Submissions: 139656
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * 
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * 
 * 
 * Note:
 * The relative order inside both the even and odd groups should remain as it
 * was in the input. 
 * The first node is considered odd, the second node even and so on ...
 * 
 * 
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode h1(0), h2(0);
        ListNode *p1 = &h1, *p2 = &h2, *p = head;

        int i = 0;
        while (p) {
            if (++i % 2) { p1->next = p; p1 = p; }
            else { p2->next = p; p2 = p; }
            p = p->next;
        }

        p1->next = h2.next;
        p2->next = NULL;
        return h1.next;
    }
};
