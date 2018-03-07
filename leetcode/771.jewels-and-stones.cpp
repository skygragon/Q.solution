/*
 * [782] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (82.70%)
 * Total Accepted:    21.3K
 * Total Submissions: 25.8K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.  Each character in S is a type of stone
 * you have.  You want to know how many of the stones you have are also
 * jewels.
 * 
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type
 * of stone from "A".
 * 
 * Example 1:
 * 
 * 
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: J = "z", S = "ZZ"
 * Output: 0
 * 
 * 
 * Note:
 * 
 * 
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 * 
 */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> m;
        for (auto c: S) ++m[c];

        int cnt = 0;
        for (auto c: J) cnt += m[c];
        return cnt; 
    }
};
