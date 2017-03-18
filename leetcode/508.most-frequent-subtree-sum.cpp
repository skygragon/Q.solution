/*
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum
 *
 * Medium (51.60%)
 * Total Accepted:    4165
 * Total Submissions: 7980
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> count;

    int next(TreeNode *p) {
        if (!p) return 0;
        int sum = p->val + next(p->left) + next(p->right);
        ++count[sum];
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        next(root);

        vector<int> v;
        int n = 0;
        for (auto &p : count) {
            if (p.second > n) {
                n = p.second;
                v.clear();
                v.push_back(p.first);
            } else if (p.second == n) {
                v.push_back(p.first);
            }
        }
        return v;
    }
};
