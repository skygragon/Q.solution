/*
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary
 *
 * Medium (28.39%)
 * Total Accepted:    30487
 * Total Submissions: 107389
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 * 
 * 
 * Note:
 * 
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * 
 * 
 * 
 * 
 * ⁠   Example 1:
 * ⁠   tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR",
 * "SFO"]]
 * ⁠   Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 * 
 * 
 * ⁠   Example 2:
 * ⁠   tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * ⁠   Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 * ⁠   Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> cur, res;
    int n;

    void next(const string &s) {
        if (!res.empty()) return;
        if (cur.size() == n) { res = cur; return; }

        auto it = m.find(s); if (it == m.end()) return;
        auto &v = it->second;

        for (int i = 0; i < v.size(); ++i) {
            string s1 = v[i];
            if (s1.empty()) continue;

            v[i] = ""; cur.push_back(s1);
            next(s1);
            v[i] = s1; cur.pop_back();
        }
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto &p : tickets) m[p.first].push_back(p.second);
        for (auto &p : m) { auto &v = p.second; sort(v.begin(), v.end()); }
        n = tickets.size()+1;

        cur.push_back("JFK");
        next("JFK");
        return res;
    }
};
