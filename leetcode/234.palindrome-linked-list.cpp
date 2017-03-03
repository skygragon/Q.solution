/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list
 *
 * Easy (31.89%)
 * Total Accepted:    90312
 * Total Submissions: 283171
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    ListNode* reverse(ListNode* p) {
        ListNode* p1 = p;
        while (p1->next) {
            ListNode* p2 = p1->next;
            p1->next = p2->next;
            p2->next = p;
            p = p2;
        }
        return p;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* p1 = head;
        if (!p1) return true;

        ListNode* p2 = head->next;
        if (!p2) return true;

        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        p2 = reverse(p1->next);
        p1 = head;
        while (p1 && p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
