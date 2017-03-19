/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule
 *
 * Medium (30.97%)
 * Total Accepted:    73101
 * Total Submissions: 235956
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So it is possible.
 * 
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0, and to take course 0 you should also have finished course
 * 1. So it is impossible.
 * 
 * Note:
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
class Solution {
public:
    vector<vector<bool>> vv;
    unordered_set<int> cur;
    unordered_map<int, bool> cache;
    int n;

    bool next(int i) {
        if (cache.find(i) != cache.end()) return cache[i];

        if (cur.find(i) != cur.end()) return cache[i] = false;
        cur.insert(i);

        for (int j = 0; j < n; ++j) {
            if (!vv[i][j]) continue;
            if (!next(j)) return cache[i] = false;
        }

        cur.erase(i);
        return cache[i] = true;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        n = numCourses;

        vv.resize(n);
        for (auto &v : vv) v.resize(n, false);
        for (auto &p : prerequisites) vv[p.first][p.second] = true;

        for (int i = 0; i < n; ++i) {
            if (!next(i)) return false;
        }
        return true;
    }
};
