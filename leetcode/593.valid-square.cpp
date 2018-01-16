/*
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (40.10%)
 * Total Accepted:    9.4K
 * Total Submissions: 23.4K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space, return whether the four
 * points could construct a square.
 * 
 * The coordinate (x,y) of a point is represented by an integer array with two
 * integers.
 * 
 * Example:
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: True
 * 
 * 
 * 
 * ⁠Note: 
 * 
 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * Input points have no order.
 * 
 * 
 */
class Solution {
public:
    using Point = vector<int>;

    int dist(Point &p1, Point &p2) { return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]); }
    Point mid(Point &p1, Point &p2) { return {p1[0]+p2[0], p1[1]+p2[1]}; }
    bool isRightAngle(Point &p1, Point &p2, Point &p3) {
        return dist(p1, p2) > 0 &&
            dist(p1, p2) == dist(p1, p3) &&
            dist(p1, p2) + dist(p1, p3) == dist(p2, p3);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (mid(p1, p2) == mid(p3, p4)) return isRightAngle(p1, p3, p4);
        if (mid(p1, p3) == mid(p2, p4)) return isRightAngle(p1, p2, p4);
        if (mid(p1, p4) == mid(p2, p3)) return isRightAngle(p1, p2, p3);
        return false;
    }
};

