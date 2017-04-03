/*
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self
 *
 * Hard (34.00%)
 * Total Accepted:    29245
 * Total Submissions: 85952
 * Testcase Example:  '[5,2,6,1]'
 *
 * 
 * You are given an integer array nums and you have to return a new counts
 * array.
 * The counts array has the property where counts[i] is 
 * the number of smaller elements to the right of nums[i].
 * 
 * 
 * Example:
 * 
 * 
 * Given nums = [5, 2, 6, 1]
 * 
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 * 
 * 
 * Return the array [2, 1, 1, 0].
 * 
 */
class Solution {
public:
    typedef struct Item { int v, i, c; } Item;
    vector<Item> v, v1;

    void merge(int b, int e, int k) {
        int i1 = b, j1 = k-1, i2 = k, j2 = e;
        int i = i1;
        while (i1 <= j1 && i2 <= j2) {
            if (v[i1].v <= v[i2].v) {
                v1[i++] = v[i1++];
            } else {
                v1[i++] = v[i2++];
                for (int x = i1; x <= j1; ++x) ++v[x].c;
            }
        }
        while (i1 <= j1) v1[i++] = v[i1++];
        while (i2 <= j2) v1[i++] = v[i2++];

        for (i = b; i <= e; ++i) v[i] = v1[i];
    }

    void mergeSort(int b, int e) {
        if (b >= e) return;
        int k = b+(e-b)/2;
        mergeSort(b, k); mergeSort(k+1, e);
        merge(b, e, k+1);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        v.resize(n); v1.resize(n);
        for (int i = 0; i < n; ++i) {
            v[i].v = nums[i]; v[i].i = i; v[i].c = 0;
        }
        mergeSort(0, n-1);

        vector<int> count(n, 0);
        for (int i = 0; i < n; ++i) count[v[i].i] = v[i].c;
        return count;
    }
};
