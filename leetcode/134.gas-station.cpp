/*
 * [134] Gas Station
 *
 * https://leetcode.com/problems/gas-station
 *
 * Medium (28.77%)
 * Total Accepted:    79113
 * Total Submissions: 274968
 * Testcase Example:  '[4]\n[5]'
 *
 * 
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i].
 * 
 * 
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from station i to its next station (i+1). You begin the journey with
 * an empty tank at one of the gas stations.
 * 
 * 
 * 
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 * 
 * 
 * 
 * Note:
 * The solution is guaranteed to be unique.
 * 
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); if (n == 0) return -1;

        int cur = 0, total = 0, j = -1;
        for (int i = 0; i < n; ++i) {
            cur += gas[i]-cost[i];
            total += gas[i]-cost[i];
            if (cur < 0) { cur = 0; j = i; }
        }

        return total < 0 ? -1 : j+1;
    }
};
