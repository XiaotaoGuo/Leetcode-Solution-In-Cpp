/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (45.73%)
 * Likes:    2150
 * Dislikes: 296
 * Total Accepted:    514.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 *
 *
 */

// @lc code=start
#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        bool flag = false;
        int ptr1 = a.length() - 1, ptr2 = b.length() - 1;
        std::string result = "";
        while (ptr1 >= 0 || ptr2 >= 0) {
            int sum = 0;
            if (ptr1 >= 0 && a[ptr1] == '1') {
                sum++;
            }
            if (ptr2 >= 0 && b[ptr2] == '1') {
                sum++;
            }
            if (flag) {
                sum++;
                flag = false;
            }
            if (sum >= 2) {
                flag = true;
                sum -= 2;
            }

            ptr1--;
            ptr2--;
            result += '0' + sum;
        }

        if (flag) {
            result += '1';
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
