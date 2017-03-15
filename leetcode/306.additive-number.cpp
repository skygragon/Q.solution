/*
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number
 *
 * Medium (27.28%)
 * Total Accepted:    21925
 * Total Submissions: 80366
 * Testcase Example:  '"112358"'
 *
 * Additive number is a string whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 * 
 * 
 * For example:
 * "112358" is an additive number because the digits can form an additive
 * sequence: 1, 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99,
 * 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * 
 * 
 * 
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 * 
 * 
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 * 
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 * 
 * 
 * Credits:Special thanks to @jeantimex for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    vector<int> cache;
    string s;
    int n;

    string add(const string &s1, const string &s2) {
        int i = s1.size()-1, j = s2.size()-1, x = 0;
        string str;
        while (i >= 0 || j >= 0 || x > 0) {
            if (i >= 0) { x += s1[i]-'0'; --i; }
            if (j >= 0) { x += s2[j]-'0'; --j; }
            str = to_string(x%10) + str;
            x /= 10;
        }
        return str;
    }

    bool next(int i, int j, int k) {
        if (k >= n) return true;

        int key = i*n*n+j*n+k;
        if (cache[key] >= 0) return cache[key];

        string s1 = s.substr(i, j-i);
        string s2 = s.substr(j, k-j);
        if (s1.size() > 1 && s1[0] == '0') return cache[key] = false;
        if (s2.size() > 1 && s2[0] == '0') return cache[key] = false;

        string sum = add(s1, s2);
        bool x = s.substr(k, sum.size()) == sum && next(j, k, k+sum.size());
        return cache[key] = x;
    }

    bool isAdditiveNumber(string num) {
        s = num; n = s.size();
        cache.resize(n*n*n, -1);

        for (int i = 1; i < n-1; ++i)
            for (int j = i+1; j < n; ++j) {
                if (next(0, i, j)) return true;
            }

        return false;
    }
};
