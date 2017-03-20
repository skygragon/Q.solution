/*
 * [382] Linked List Random Node
 *
 * https://leetcode.com/problems/linked-list-random-node
 *
 * Medium (46.38%)
 * Total Accepted:    22760
 * Total Submissions: 49013
 * Testcase Example:  '["Solution","getRandom"]\n[[[1,2,3]],[]]'
 *
 * Given a singly linked list, return a random node's value from the linked
 * list. Each node must have the same probability of being chosen.
 * 
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you?
 * Could you solve this efficiently without using extra space?
 * 
 * 
 * Example:
 * 
 * // Init a singly linked list [1,2,3].
 * ListNode head = new ListNode(1);
 * head.next = new ListNode(2);
 * head.next.next = new ListNode(3);
 * Solution solution = new Solution(head);
 * 
 * // getRandom() should return either 1, 2, or 3 randomly. Each element should
 * have equal probability of returning.
 * solution.getRandom();
 * 
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
    ListNode* p;
    int n;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        n = 0; p = head;
        ListNode* p1 = p;
        while(p1) { ++n; p1 = p1->next; }
        srand((unsigned)time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int x = rand() % n;
        ListNode* p1 = p;
        while (x) { p1 = p1->next; --x; }
        return p1->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
