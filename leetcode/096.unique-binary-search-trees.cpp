/*
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees
 *
 * Medium (40.09%)
 * Total Accepted:    112231
 * Total Submissions: 279634
 * Testcase Example:  '1'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1...n?
 * 
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
class Solution {
public:
    int numTrees(int n) {
        vector<int> count(n+1, 0);
        count[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; ++j) count[i] += count[j]*count[i-1-j];
        return count[n];
    }
};
