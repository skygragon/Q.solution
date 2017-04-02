/*
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number
 *
 * Hard (12.66%)
 * Total Accepted:    62494
 * Total Submissions: 493741
 * Testcase Example:  '"3"'
 *
 * Validate if a given string is numeric.
 * 
 * 
 * Some examples:
 * "0" => true
 * "   0.1  " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * 
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one.
 * 
 * 
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button  to reset your code definition.
 * 
 */
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i = 0, j = n-1;
        while (i < n && s[i] == ' ') ++i;
        while (j >= 0 && s[j] == ' ') --j;
        if (i > j) return false;

        enum State {
            NONE,
            SIGN1,
            NUMBER1,
            DOT,
            NUMBER2,
            E,
            SIGN2,
            NUMBER3
        };

        State state = NONE;
        bool hasNumber1 = false, hasNumber2 = false;
        for(; i <= j; ++i) {
            char c = s[i];
            if (c == '+' || c == '-') {
                if (state == NONE) state = SIGN1;
                else if (state == E) state = SIGN2;
                else return false;
            } else if (c >= '0' && c <= '9') {
                if (state == NONE || state == SIGN1) { state = NUMBER1; hasNumber1 = true; }
                else if (state == DOT) { state = NUMBER2; hasNumber2 = true; }
                else if (state == SIGN2 || state == E) state = NUMBER3;
            } else if (c == 'e' || c == 'E') {
                if (state != NUMBER2 && state != NUMBER1 && state != DOT) return false;
                state = E;
            } else if (c == '.') {
                if (state != NUMBER1 && state != SIGN1 && state != NONE) return false;
                state = DOT;
            } else {
                return false;
            }
        }

        if (!hasNumber1 && !hasNumber2) return false;
        if (state == E || state == SIGN1 || state == SIGN2) return false;

        return true;
    }
};
