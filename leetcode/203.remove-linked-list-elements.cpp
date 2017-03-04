/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements
 *
 * Easy (31.33%)
 * Total Accepted:    101410
 * Total Submissions: 323666
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode node(0);

        ListNode* p = head;
        head = &node;

        while (p) {
            if (p->val != val) { head->next = p; head = p; }
            p = p->next;
        }
        head->next = NULL;

        return node.next;
    }
};
