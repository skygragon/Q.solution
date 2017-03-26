/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division
 *
 * Medium (40.10%)
 * Total Accepted:    12786
 * Total Submissions: 31890
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 * 
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * 
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
class Solution {
public:
    vector<vector<double>> vv;
    unordered_map<string, int> index;
    vector<bool> used;

    double next(int i, int e) {
        if (i == e) return 1.0;
        used[i] = true;

        double x = -1.0;
        for (int j = 0; j < vv.size() && x < 0; ++j) {
            if (vv[i][j] == 0.0 || used[j]) continue;
            if (j == e) x = vv[i][j];
            else x = next(j, e) * vv[i][j];
        }
        if (x < 0) x = -1.0;
        used[i] = false;
        return x;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int k = 0;
        for (int i = 0; i < equations.size(); ++i) {
            auto &p = equations[i];
            if (index.find(p.first) == index.end()) index[p.first] = k++;
            if (index.find(p.second) == index.end()) index[p.second] = k++;
        }
        used.resize(k, false);
        vv.resize(k);
        for (auto &v : vv) v.resize(k, 0.0);

        for (int k = 0; k < equations.size(); ++k) {
            auto &p = equations[k];
            int i = index[p.first], j = index[p.second];
            vv[i][j] = values[k];
            vv[j][i] = 1.0 / values[k];
        }

        vector<double> v;
        for (auto &p : queries) {
            string b = p.first, e = p.second;
            double x = -1;
            if (index.find(b) != index.end() && index.find(e) != index.end())
                x = next(index[b], index[e]);
            v.push_back(x);
        }
        return v;
    }
};
