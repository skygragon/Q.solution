/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses
 *
 * Medium (26.20%)
 * Total Accepted:    77105
 * Total Submissions: 294290
 * Testcase Example:  '"0000"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * 
 * For example:
 * Given "25525511135",
 * 
 * 
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * 
 */
class Solution {
public:
    vector<string> vs;
    vector<int> vi;

    void next (const string &s) {
        if (s.empty()) {
            if (vi.size() == 4) {
                string ip;
                ip = accumulate(vi.begin(), vi.end(), ip,
                        [](string ip, int x) {
                            return ip + "." + to_string(x);
                        });
                vs.push_back(ip.substr(1));
            }
            return;
        }

        if (vi.size() >= 4) return;

        for (int i = 1; i <= 3 && i <= s.size(); ++i) {
            if (i > 1 && s[0] == '0') continue;
            int x = stoi(s.substr(0, i));
            if (x > 255) continue;

            vi.push_back(x);
            next(s.substr(i));
            vi.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        next(s);
        return vs;
    }
};
