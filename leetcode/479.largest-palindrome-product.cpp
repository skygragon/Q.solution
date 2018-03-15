/*
 * [479] Largest Palindrome Product
 *
 * https://leetcode.com/problems/largest-palindrome-product/description/
 *
 * algorithms
 * Easy (25.36%)
 * Total Accepted:    9.1K
 * Total Submissions: 35.7K
 * Testcase Example:  '1'
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 * ⁠Since the result could be very large, you should return the largest
 * palindrome mod 1337.
 * 
 * Example:
 * Input: 2
 * Output: 987
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 * 
 * 
 * 
 * 
 * Note:
 * The range of n is [1,8].
 * 
 * 
 */
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        int M = stoi(string(n, '9')), N = stoi(string(n-1,'9'))+1;
        for (int i = M; i >= N; --i) {
            string s = to_string(i), s1 = s;
            reverse(s1.begin(), s1.end());
            s += s1;

            long long x = stoll(s);
            for (int j = M; j >= N; --j) {
                if (x % j == 0 && x/j >= N && x/j <= M) return x % 1337;
                if (x/j > j) break;
            }
        }
        return 0;
    }
};
