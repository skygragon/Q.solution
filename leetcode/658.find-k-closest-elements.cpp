/*
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements
 *
 * algorithms
 * Medium (35.84%)
 * Total Accepted:    4.7K
 * Total Submissions: 13.3K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 104
 * ⁠Absolute value of elements in the array and x will not exceed 104
 * 
 * 
 */
class Solution {
public:
    int find(const vector<int> &v, int x) {
        int i = 0, j = v.size();
        while (i < j) {
            int m = i+(j-i)/2;
            if (v[m] == x) return m;
            else if (v[m] > x) j = m;
            else i = m+1;
        }
        return i;
    }

    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        int i = find(v, x), j = i-1, n = v.size();
        while (k--) {
            if (i == n) j--;
            else if (j == -1) i++;
            else if (abs(v[i]-x) >= abs(v[j]-x)) j--;
            else i++;
        }
        return vector<int>(v.begin()+j+1, v.begin()+i);
    }
};
