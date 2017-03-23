/*
 * [275] H-Index II
 *
 * https://leetcode.com/problems/h-index-ii
 *
 * Medium (33.80%)
 * Total Accepted:    43433
 * Total Submissions: 128490
 * Testcase Example:  '[]'
 *
 * 
 * Follow up for H-Index: What if the citations array is sorted in ascending
 * order? Could you optimize your algorithm?
 * 
 * 
 * 
 * ⁠ Expected runtime complexity is in O(log n) and the input is sorted.
 * 
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;

        int i = 0, j = n-1, x = 0;
        while (i <= j) {
            int m = i+(j-i)/2;
            if (citations[m] >= n-m) { j = m-1; x = max(x, n-m); }
            else i = m+1;
        }
        return x;
    }
};
