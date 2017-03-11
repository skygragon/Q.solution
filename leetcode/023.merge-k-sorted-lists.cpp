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
        int n = lists.size();
        if (n == 0) return NULL;

        auto comp = [](ListNode* p1, ListNode* p2) { return p1->val > p2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        unordered_map<ListNode*, int> m;

        ListNode node(0);
        ListNode *p = &node, *head = NULL;

        for (int i = 0; i < n; ++i) {
            head = lists[i];
            if (!head) continue;
            q.push(head); m[head] = i;
        }

        while (!q.empty()) {
            ListNode* p1 = q.top(); q.pop();

            int i = m[p1]; m.erase(p1);
            head = lists[i] = lists[i]->next;
            if (head) {
                q.push(head);
                m[head] = i;
            }

            p->next = p1; p = p->next; p->next = NULL;
        }

        return node.next;
    }
};
