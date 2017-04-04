/*
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable
 *
 * Medium (19.25%)
 * Total Accepted:    29281
 * Total Submissions: 151719
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * 
 * Note:
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 
 * 
 */
class NumArray {
public:
    vector<int> nums, bit;
    int n;

    NumArray(vector<int> nums) {
        this->nums = nums;
        n = nums.size();
        bit.resize(n+1, 0);
        for (int i = 0; i < n; ++i) bitSet(i+1, nums[i]);
    }

    void bitSet(int i, int val) {
        while (i <= n) { bit[i] += val; i += (i & -i); }
    }

    int bitGet(int i) {
        int s = 0;
        while (i >= 1) { s += bit[i]; i -= (i & -i); }
        return s;
    }

    void update(int i, int val) {
        int d = val - nums[i];
        nums[i] = val;
        bitSet(i+1, d);
    }

    int sumRange(int i, int j) {
        return bitGet(j+1) - bitGet(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
