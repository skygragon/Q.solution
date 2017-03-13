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
    using HT = pair<ListNode*, ListNode*>;

    HT next(ListNode* p) {
        if (!p || !p->next) return {p, p};

        ListNode left(0), right(0), cur(0);
        ListNode *p1 = p, *pl = &left, *pr = &right, *pc = &cur;

        while (p1) {
            if (p1->val < p->val) { pl->next = p1; pl = pl->next; }
            if (p1->val > p->val) { pr->next = p1; pr = pr->next; }
            if (p1->val == p->val) { pc->next = p1; pc = pc->next; }
            p1 = p1->next;
        }
        pl->next = pr->next = pc->next = NULL;

        auto l = next(left.next);
        auto r = next(right.next);

        pl = l.first ? l.first : cur.next;
        pr = r.second ? r.second : pc;

        if (l.second) l.second->next = cur.next;
        pc->next = r.first;

        return {pl, pr};
    }

    ListNode* sortList(ListNode* head) {
        auto x = next(head);
        return x.first;
    }
};
