/*
 * [762] Find Anagram Mappings
 *
 * https://leetcode.com/problems/find-anagram-mappings/description/
 *
 * algorithms
 * Easy (80.23%)
 * Total Accepted:    5.9K
 * Total Submissions: 7.4K
 * Testcase Example:  '[12,28,46,32,50]\n[50,12,32,46,28]'
 *
 * 
 * Given two lists Aand B, and B is an anagram of A. B is an anagram of A means
 * B is made by randomizing the order of the elements in A.
 * 
 * We want to find an index mapping P, from A to B. A mapping P[i] = j means
 * the ith element in A appears in B at index j.
 * 
 * These lists A and B may contain duplicates.  If there are multiple answers,
 * output any of them.
 * 
 * 
 * 
 * For example, given
 * 
 * A = [12, 28, 46, 32, 50]
 * B = [50, 12, 32, 46, 28]
 * 
 * 
 * We should return
 * 
 * [1, 4, 3, 2, 0]
 * 
 * as P[0] = 1 because the 0th element of A appears at B[1],
 * and P[1] = 4 because the 1st element of A appears at B[4],
 * and so on.
 * 
 * 
 * Note:
 * A, B have equal lengths in range [1, 100].
 * A[i], B[i] are integers in range [0, 10^5].
 * 
 */
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, stack<int>> m;
        
        int n = A.size();
        for (int i = 0; i < n; ++i) m[B[i]].push(i);
        
        vector<int> C(n);
        for (int i = 0; i < n; ++i) { C[i] = m[A[i]].top(); m[A[i]].pop(); }
        return C;
    }
};
