/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string
 *
 * Easy (37.65%)
 * Total Accepted:    67058
 * Total Submissions: 178008
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * 
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 */
class Solution {
public:
    const string VOWELS = "aeiouAEIOU";

    string reverseVowels(string s) {
        vector<int> v;
        for (int i = 0; i < s.size(); ++i) {
            if (VOWELS.find(s[i]) != string::npos)
                v.push_back(i);
        }

        for (int i = 0, j = v.size() -1; i < j; ++i, --j)
            swap(s[v[i]], s[v[j]]);

        return s;
    }
};
