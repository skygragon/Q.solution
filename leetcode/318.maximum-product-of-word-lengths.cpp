/*
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths
 *
 * Medium (42.95%)
 * Total Accepted:    45120
 * Total Submissions: 105040
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 
 * ⁠   Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters.
 * ⁠   You may assume that each word will contain only lower case letters.
 * ⁠   If no such two words exist, return 0.
 * 
 * 
 * 
 * ⁠   Example 1:
 * 
 * 
 * ⁠   Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * ⁠   Return 16
 * ⁠   The two words can be "abcw", "xtfn".
 * 
 * 
 * ⁠   Example 2:
 * 
 * 
 * ⁠   Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * ⁠   Return 4
 * ⁠   The two words can be "ab", "cd".
 * 
 * 
 * ⁠   Example 3:
 * 
 * 
 * ⁠   Given ["a", "aa", "aaa", "aaaa"]
 * ⁠   Return 0
 * ⁠   No such pair of words.    
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bit(n), len(n);
        for (int i = 0; i < n; ++i) {
            len[i] = words[i].size();
            for (char c : words[i]) bit[i] |= (1 << (c-'a'));
        }

        int x = 0;
        for (int i = 0; i < n-1; ++i)
            for (int j = i+1; j < n; ++j)
                if ((bit[i] & bit[j]) == 0) x = max(x, len[i]*len[j]);

        return x;
    }
};
