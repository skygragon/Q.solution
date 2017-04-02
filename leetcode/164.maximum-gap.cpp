/*
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap
 *
 * Hard (28.98%)
 * Total Accepted:    44830
 * Total Submissions: 154652
 * Testcase Example:  '[]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size(); if (n < 2) return 0;
        vector<int> l(n, -1), h(n, -1);

        auto p = minmax_element(nums.begin(), nums.end());
        int m = *p.first, M = *p.second, k = (M-m-1)/(n-1)+1;
        for (auto num : nums) {
            if (num == m || num == M) continue;
            int i = (num-m)/k;
            if (l[i] == -1 || l[i] > num) l[i] = num;
            if (h[i] == -1 || h[i] < num) h[i] = num;
        }

        int x = 0, last = -1;
        for (int i = 0; i < n; ++i) {
            if (l[i] == -1 || h[i] == -1) continue;
            x = max(x, l[i]-(last == -1 ? m : h[last]));
            last = i;
        }
        x = max(x, M-(last == -1 ? m : h[last]));

        return x;
    }
};
