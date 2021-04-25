/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (52.60%)
 * Likes:    4915
 * Dislikes: 231
 * Total Accepted:    321.8K
 * Total Submissions: 605.9K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 *
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */

// @lc code=start
#include <stack>
#include <string>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::string res = "";
        std::stack<int> count_stk;
        std::stack<std::string> str_stk;
        int ptr = 0;
        while (ptr < s.length()) {
            if (std::isdigit(s[ptr])) {
                int count = 0;
                while (ptr < s.length() && std::isdigit(s[ptr])) {
                    count *= 10;
                    count += s[ptr] - '0';
                    ptr++;
                }
                count_stk.push(count);
            } else if (s[ptr] == '[') {
                ptr++;
                std::string temp_str = "";
                while (ptr < s.length() && std::isalpha(s[ptr])) {
                    temp_str += s[ptr];
                    ptr++;
                }
                str_stk.push(temp_str);
            } else if (s[ptr] == ']') {
                std::string new_str = "";
                for (int i = 0; i < count_stk.top(); ++i) {
                    new_str += str_stk.top();
                }
                str_stk.pop();
                count_stk.pop();

                if (count_stk.empty()) {
                    res += new_str;
                } else {
                    str_stk.top() += new_str;
                }
                ptr++;
            } else {
                if (std::isalpha(s[ptr])) {
                    if (str_stk.empty()) {
                        res += s[ptr];
                    } else {
                        str_stk.top() += s[ptr];
                    }
                }
                ptr++;
            }
        }

        return res;
    }
};
// @lc code=end
