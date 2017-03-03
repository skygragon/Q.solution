/*
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row
 *
 * Easy (60.49%)
 * Total Accepted:    11582
 * Total Submissions: 19161
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * Note:
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
/*
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row
 *
 * Easy (60.21%)
 * Total Accepted:    9404
 * Total Submissions: 15615
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * Note:
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
class Solution {
public:
    vector<string> ROWS = {
        "qwertyuiopQWERTYUIOP",
        "asdfghjklASDFGHJKL",
        "zxcvbnmZXCVBNM"
    };

    vector<string> findWords(vector<string>& words) {
        vector<string> v;

        for (const auto& s : words) {
            for (const auto& row: ROWS) {
                if (s.find_first_of(row) != string::npos &&
                    s.find_first_not_of(row) == string::npos) {
                    v.push_back(s);
                    break;
                }
            }
        }

        return v;
    }
};

