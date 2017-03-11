/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer
 *
 * Medium (26.58%)
 * Total Accepted:    100116
 * Total Submissions: 376580
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;

        RandomListNode *p = head, *p1;
        while (p) {
            p1 = new RandomListNode(p->label);
            p1->next = p->next; p->next = p1; p = p1->next;
        }

        p = head;
        while (p) {
            if (p->random) p->next->random = p->random->next;
            p = p->next->next;
        }

        RandomListNode node(0);
        p = head; head = &node;
        while (p) {
            head->next = p->next;
            head = head->next;
            p->next = p->next->next;
            p = p->next;
        }
        head->next = NULL;
        return node.next;
    }
};
