/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists
 *
 * Easy (30.16%)
 * Total Accepted:    116114
 * Total Submissions: 384959
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ↘
 * c1 → c2 → c3
 * ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
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
    int len(ListNode* p) {
        int x = 0;
        while (p) { p = p->next; ++x; }
        return x;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int z = len(headA) - len(headB);
        while (z > 0) { headA = headA->next; --z; }
        while (z < 0) { headB = headB->next; ++z; }

        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
