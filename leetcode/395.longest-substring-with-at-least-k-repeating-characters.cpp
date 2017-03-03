/*
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
 *
 * Medium (35.50%)
 * Total Accepted:    10809
 * Total Submissions: 30446
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 * 
 * 
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, set<int>> m;
        for (int i = 0; i < s.size(); ++i) m[s[i]].insert(i);

        int len = 0;
        queue<pair<int, int>> q;
        q.push({0, s.size()-1});

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i > j) continue;

            set<int> points;
            bool possible = false, found = true;
            for (auto& p : m) {
                auto b = p.second.lower_bound(i);
                auto e = p.second.upper_bound(j);
                int n = distance(b, e);

                if (n >= k) {
                    possible = true;
                } else if (n > 0) {
                    found = false;
                    points.insert(b, e);
                }
            }

            // pruning
            if (!possible) continue;
            if (found) { len = max(len, j-i+1); continue; }

            int last = i-1;
            for (auto point : points) {
                q.push({last+1, point-1});
                last = point;
            }
            q.push({last+1, j});
        }

        return len;
    }
};
