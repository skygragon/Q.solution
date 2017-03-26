/*
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow
 *
 * Medium (33.58%)
 * Total Accepted:    13775
 * Total Submissions: 41006
 * Testcase Example:  '2\n[3]'
 *
 * 
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is
 * an extremely large positive integer given in the form of an array.
 * 
 * 
 * Example1:
 * 
 * a = 2
 * b = [3]
 * 
 * Result: 8
 * 
 * 
 * 
 * Example2:
 * 
 * a = 2
 * b = [1,0]
 * 
 * Result: 1024
 * 
 * 
 * 
 * Credits:Special thanks to @Stomach_ache for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int M = 1337;

    int powM(int a, int n) {
        int x = 1;
        while (n--) x = x * a % M;
        return x;
    }

    int superPow(int a, vector<int>& b) {
        a %= M;

        vector<int> v(10, 1);
        for (int i = 1; i < 10; ++i) v[i] = v[i-1] * a % M;

        int x = 1;

        reverse(b.begin(), b.end());
        for (int i = 0; i < b.size(); ++i) {
            int y = v[b[i]], k = i;
            while (k--) y = powM(y, 10);
            x = x * y % M;
        }
        return x;
    }
};
