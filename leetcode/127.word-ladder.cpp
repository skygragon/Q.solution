/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder
 *
 * Medium (19.23%)
 * Total Accepted:    112794
 * Total Submissions: 586439
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * 
 * For example,
 * 
 * 
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * 
 * Note:
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * 
 * 
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
    bool connected(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) return false;
        int m = 0;
        for (int i = 0; i < s1.size(); ++i) if (s1[i] != s2[i]) ++m;
        return m == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> v;
        v.push_back(beginWord);
        v.insert(v.end(), wordList.begin(), wordList.end());

        auto it = find(v.begin(), v.end(), endWord);
        if (it == v.end()) return 0;
        int i = it - v.begin();

        int n = v.size();
        vector<int> distances(n, -1);
        distances[i] = 1;

        vector<bool> conn(n*n);
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j) {
                if (!connected(v[i], v[j])) continue;
                conn[i*n+j] = conn[j*n+i] = true;
            }

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (int j = 0; j < n; ++j) {
                if (!conn[i*n+j]) continue;
                if (distances[j] == -1 || distances[i]+1 < distances[j]) {
                    distances[j] = distances[i]+1;
                    q.push(j);
                }
            }
        }

        return max(distances[0], 0);
    }
};
