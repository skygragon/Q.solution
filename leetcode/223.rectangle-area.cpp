/*
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area
 *
 * Medium (32.19%)
 * Total Accepted:    57823
 * Total Submissions: 179621
 * Testcase Example:  '-2\n-2\n2\n2\n-2\n-2\n2\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem, creating the
 * above image and all test cases.
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap;
        if (E >= C || A >= G) overlap = 0;
        else if (F >= D || B >= H) overlap = 0;
        else {
            int w = min(C, G) - max(A, E);
            int h = min(D, H) - max(B, F);
            overlap = w * h;
        }

        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F);

        return s1 + s2 - overlap;
    }
};
