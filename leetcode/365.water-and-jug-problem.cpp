/*
 * [365] Water and Jug Problem
 *
 * https://leetcode.com/problems/water-and-jug-problem
 *
 * Medium (26.52%)
 * Total Accepted:    12376
 * Total Submissions: 46646
 * Testcase Example:  '3\n5\n4'
 *
 * You are given two jugs with capacities x and y litres. There is an infinite
 * amount of water supply available.
 * You need to determine whether it is possible to measure exactly z litres
 * using these two jugs.
 * 
 * If z liters of water is measurable, you must have z liters of water
 * contained within one or both buckets by the end.
 * 
 * 
 * Operations allowed:
 * 
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full
 * or the first jug itself is empty.
 * 
 * 
 * 
 * Example 1: (From the famous "Die Hard" example)
 * 
 * Input: x = 3, y = 5, z = 4
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: x = 2, y = 6, z = 5
 * Output: False
 * 
 * 
 * 
 * Credits:Special thanks to @vinod23 for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x < y) swap(x, y);
        if (y == 0) return x == z || z == 0;

        int x1 = x;
        while (true) {
            if (x1 == z || y == z) return true;
            if (x1 + y == z) return true;
            if (x1 <= y && x1 + x == z) return true;
            if (x1 == 0) break;

            if (x1 >= y) x1 -= y;
            else x1 = x - (y-x1);
        }
        return false;
    }
};
