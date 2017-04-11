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
    void next(TreeLinkNode *p) {
        if (!p) return;

        TreeLinkNode node(0), *cur = &node;
        for (; p; p = p->next) {
            if (p->left) { cur->next = p->left; cur = cur->next; }
            if (p->right) { cur->next = p->right; cur = cur->next; }
        }

        next(node.next);
    }

    void connect(TreeLinkNode *root) {
        next(root);
    }
};
