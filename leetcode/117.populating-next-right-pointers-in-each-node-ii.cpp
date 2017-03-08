/*
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
 *
 * Medium (33.60%)
 * Total Accepted:    87522
 * Total Submissions: 260465
 * Testcase Example:  '{}'
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree? Would your previous
 * solution still work?
 * 
 * Note:
 * You may only use constant extra space.
 * 
 * 
 * For example,
 * Given the following binary tree,
 * 
 * ⁠        1
 * ⁠      /  \
 * ⁠     2    3
 * ⁠    / \    \
 * ⁠   4   5    7
 * 
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * ⁠        1 -> NULL
 * ⁠      /  \
 * ⁠     2 -> 3 -> NULL
 * ⁠    / \    \
 * ⁠   4-> 5 -> 7 -> NULL
 * 
 * 
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;

        queue<TreeLinkNode*> q;
        q.push(root);
        int cur = 1, next = 0;
        TreeLinkNode* last = NULL;

        while (!q.empty()) {
            TreeLinkNode* p = q.front();
            q.pop();

            if (p->left) { q.push(p->left); ++next; }
            if (p->right) { q.push(p->right); ++next; }
            if (last) last->next = p;
            last = p;

            if (--cur == 0) {
                last = NULL;
                swap(cur, next);
            }
        }
    }
};
