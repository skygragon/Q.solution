/*
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference
 *
 * Medium (44.44%)
 * Total Accepted:    2940
 * Total Submissions: 6588
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */
class Solution {
public:
    int getMinutes(const string &s) {
        return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (auto s : timePoints) v.push_back(getMinutes(s));

        sort(v.begin(), v.end());
        v.push_back(v[0]+24*60);

        int x = 25*60;
        for (int i = 1, n = v.size(); i < n; ++i) x = min(x, v[i]-v[i-1]);
        return x;
    }
};
