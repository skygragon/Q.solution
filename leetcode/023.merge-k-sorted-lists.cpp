/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists
 *
 * Hard (26.35%)
 * Total Accepted:    133130
 * Total Submissions: 505228
 * Testcase Example:  '[]'
 *
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); if (n == 0) return NULL;

        auto comp = [](ListNode *p1, ListNode *p2) { return p1->val > p2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        unordered_map<ListNode*, ListNode*> m;

        ListNode node(0), *head = &node, *p = NULL;
        for (int i = 0; i < n; ++i) {
            p = lists[i]; if (!p) continue;
            q.push(p); m[p] = p->next; p->next = NULL;
        }

        while (!q.empty()) {
            ListNode *cur = q.top(); q.pop();
            ListNode *next = m[cur]; m.erase(cur);

            if (next) { q.push(next); m[next] = next->next; next->next = NULL; }
            head->next = cur; head = head->next;
        }

        return node.next;
    }
};
