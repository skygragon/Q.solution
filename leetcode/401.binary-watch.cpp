/*
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch
 *
 * Easy (44.39%)
 * Total Accepted:    22637
 * Total Submissions: 50969
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */
class Solution {
public:
    int getBitsNum(int n) {
        int x = 0;
        while (n) { n &= n-1; ++x; }
        return x;
    }

    string format(int x, int y) {
        char buf[8];
        snprintf(buf, sizeof(buf), "%d:%02d", x, y);
        return string(buf);
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> v;

        for (int i = 0; i < 12; ++i) {
            int x = getBitsNum(i);
            if (x > num) continue;

            for (int j = 0; j < 60; ++j) {
                int y = getBitsNum(j);
                if (x+y == num) v.push_back(format(i, j));
            }
        }

        return v;
    }
};
