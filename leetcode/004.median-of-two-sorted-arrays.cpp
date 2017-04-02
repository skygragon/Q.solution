/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays
 *
 * Hard (21.07%)
 * Total Accepted:    148440
 * Total Submissions: 704460
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int i = 0, j = n1-1;
        int k = (n1+n2-1)/2;

        while (i <= j) {
            int m = i+(j-i)/2;
            if (nums1[m] > nums2[k-m]) j = m-1;
            else i = m+1;
        }

        int NA_MIN = numeric_limits<int>::min(), NA_MAX = numeric_limits<int>::max();
        int a = max(j >= 0 ? nums1[j] : NA_MIN, k-i >= 0 ? nums2[k-i] : NA_MIN);
        int b = min(i < n1 ? nums1[i] : NA_MAX, k-j < n2 ? nums2[k-j] : NA_MAX);

        return ((n1+n2)%2) ? a : (a+b)/2.0;
    }
};
