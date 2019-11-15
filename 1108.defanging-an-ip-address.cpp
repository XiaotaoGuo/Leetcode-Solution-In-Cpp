/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 *
 * https://leetcode.com/problems/defanging-an-ip-address/description/
 *
 * algorithms
 * Easy (84.14%)
 * Likes:    147
 * Dislikes: 424
 * Total Accepted:    85.9K
 * Total Submissions: 101.4K
 * Testcase Example:  '"1.1.1.1"'
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP
 * address.
 * 
 * A defanged IP address replaces every period "." with "[.]".
 * 
 * 
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 * 
 * 
 * Constraints:
 * 
 * 
 * The given address is a valid IPv4 address.
 * 
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        for(char& c: address){
            if(c == '.'){
                result += '[';
            }
            result += c;
            if(c == '.'){
                result += ']';
            }
        }
        return result;
    }
};
// @lc code=end

