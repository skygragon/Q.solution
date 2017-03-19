/*
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences
 *
 * Medium (30.27%)
 * Total Accepted:    69201
 * Total Submissions: 228554
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * 
 */
class Solution {
public:
    unordered_map<int, pair<string, int>> count;

    unordered_map<char, int> m = {
        {'A', 0}, {'C', 1}, {'G', 2}, {'T', 4}
    };

    vector<string> findRepeatedDnaSequences(string s) {
        unsigned x = 0;
        for (int i = 0, n = s.size(); i <= n-10; ++i) {
            if (i > 0) {
                x = ((x << 5) >> 2) | m[s[i+9]];
            } else {
                for (int j = 0; j < 10; ++j)
                    x = (x << 3) | m[s[i+j]];
            }
            if (++count[x].second == 1)
                count[x].first = s.substr(i, 10);
        }

        vector<string> v;
        for (auto &p : count) {
            if (p.second.second > 1) v.push_back(p.second.first);
        }
        return v;
    }
};
