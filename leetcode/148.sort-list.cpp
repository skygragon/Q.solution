/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list
 *
 * Medium (27.71%)
 * Total Accepted:    96820
 * Total Submissions: 348971
 * Testcase Example:  '[]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    // HT = head and tail
    using HT = pair<ListNode*, ListNode*>;

    HT next(ListNode* p) {
        if (!p || !p->next) return {p, p};

        ListNode left(0), right(0), middle(0);
        ListNode *pl = &left, *pr = &right, *pm = &middle;

        ListNode *cur = p;
        for (; cur; cur = cur->next) {
            if (cur->val < p->val)  { pl->next = cur; pl = pl->next; }
            if (cur->val > p->val)  { pr->next = cur; pr = pr->next; }
            if (cur->val == p->val) { pm->next = cur; pm = pm->next; }
        }
        pl->next = pr->next = pm->next = NULL;

        auto l = next(left.next);
        auto r = next(right.next);

        if (l.second) l.second->next = middle.next;
        if (r.first) pm->next = r.first;

        pl = l.first ? l.first : middle.next;
        pr = r.second ? r.second : pm;
        return {pl, pr};
    }

    ListNode* sortList(ListNode* head) {
        auto l = next(head);
        return l.first;
    }
};
