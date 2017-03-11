/*
 * [455] Assign Cookies
 *
 * https://leetcode.com/problems/assign-cookies
 *
 * Easy (47.17%)
 * Total Accepted:    18062
 * Total Submissions: 38296
 * Testcase Example:  '[1,2,3]\n[1,1]'
 *
 * 
 * Assume you are an awesome parent and want to give your children some
 * cookies. But, you should give each child at most one cookie. Each child i
 * has a greed factor gi, which is the minimum size of a cookie that the child
 * will be content with; and each cookie j has a size sj. If sj >= gi, we can
 * assign the cookie j to the child i, and the child i will be content. Your
 * goal is to maximize the number of your content children and output the
 * maximum number.
 * 
 * 
 * Note:
 * You may assume the greed factor is always positive. 
 * You cannot assign more than one cookie to one child.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3], [1,1]
 * 
 * Output: 1
 * 
 * Explanation: You have 3 children and 2 cookies. The greed factors of 3
 * children are 1, 2, 3. 
 * And even though you have 2 cookies, since their size is both 1, you could
 * only make the child whose greed factor is 1 content.
 * You need to output 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2], [1,2,3]
 * 
 * Output: 2
 * 
 * Explanation: You have 2 children and 3 cookies. The greed factors of 2
 * children are 1, 2. 
 * You have 3 cookies and their sizes are big enough to gratify all of the
 * children, 
 * You need to output 2.
 * 
 * 
 */
class Solution {
public:
    int find (vector<int> &v, int x) {
        int n = v.size(), i = 0, j = n-1;
        while (i <= j) {
            int m = i+(j-i)/2;
            if (v[m] == x) return m;
            else if (v[m] > x) j = m-1;
            else i = m+1;
        }

        if (i >= n) return -1;
        if (v[i] >= x) return i;
        return i+1 < n ? i+1 : -1;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
         sort(g.begin(), g.end());
         sort(s.begin(), s.end());

         int x = 0;
         for (auto gi : g) {
             int i = find(s, gi);
             if (i == -1) continue;

             ++x;
             s.erase(s.begin() + i);
         }

         return x;
    }
};
