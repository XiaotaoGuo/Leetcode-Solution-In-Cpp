/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (36.20%)
 * Likes:    1545
 * Dislikes: 541
 * Total Accepted:    216.4K
 * Total Submissions: 587.1K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be obtained from s. You can return them in any order.
 *
 * A valid IP address consists of exactly four integers, each integer is
 * between 0 and 255, separated by single dots and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses. 
 *
 *
 * Example 1:
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * Example 2:
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * Example 3:
 * Input: s = "1111"
 * Output: ["1.1.1.1"]
 * Example 4:
 * Input: s = "010010"
 * Output: ["0.10.0.10","0.100.1.0"]
 * Example 5:
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 3000
 * s consists of digits only.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<int> current_ip;
        std::vector<std::string> ip_list;
        iterate(s, 0, current_ip, ip_list);
        return ip_list;
    }

private:
    void iterate(const std::string& s, int idx, std::vector<int>& current_ip,
                 std::vector<std::string>& ip_list) {
        if (current_ip.size() > 4 ||
            (!current_ip.empty() && current_ip.back() > 255)) {
            return;
        }

        if (idx == s.length()) {
            if (current_ip.size() == 4) {
                std::string ip = "";
                for (int i = 0; i < 3; i++) {
                    ip += std::to_string(current_ip[i]);
                    ip += ".";
                }
                ip += std::to_string(current_ip[3]);
                ip_list.push_back(ip);
            }
            return;
        }

        // option 1: add new digit to next position
        int num = s[idx] - '0';
        current_ip.push_back(num);
        iterate(s, idx + 1, current_ip, ip_list);
        current_ip.pop_back();

        // option 2: add new digit to current position only when current
        // position is not empty or 0
        if (!current_ip.empty() && current_ip.back() != 0) {
            current_ip.back() *= 10;
            current_ip.back() += num;
            iterate(s, idx + 1, current_ip, ip_list);
            current_ip.back() /= 10;
        }
    }
};
// @lc code=end
