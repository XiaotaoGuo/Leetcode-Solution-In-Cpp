/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (38.49%)
 * Likes:    2328
 * Dislikes: 360
 * Total Accepted:    266.6K
 * Total Submissions: 685.7K
 * Testcase Example:  '"3+2*2"'
 *
 * Given a string s which represents an expression, evaluate this expression
 * and return its value. 
 *
 * The integer division should truncate toward zero.
 *
 *
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of integers and operators ('+', '-', '*', '/') separated by some
 * number of spaces.
 * s represents a valid expression.
 * All the integers in the expression are non-negative integers in the range
 * [0, 2^31 - 1].
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 *
 */

// @lc code=start
#include <stack>
#include <string>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> stk;
        int idx = 0;
        int result = 0;
        char prev_op = '+';
        while (idx < s.length()) {
            if (s[idx] == ' ') {
                idx++;
                continue;
            }

            if (std::isdigit(s[idx])) {
                int val = 0;
                while (idx < s.length() && std::isdigit(s[idx])) {
                    val *= 10;
                    val += s[idx] - '0';
                    idx++;
                }

                // first val
                if (stk.empty()) {
                    stk.push(val);
                    continue;
                }

                if (prev_op == '+') {
                    stk.push(val);
                } else if (prev_op == '-') {
                    stk.push(-val);
                } else if (prev_op == '*') {
                    stk.top() *= val;
                } else if (prev_op == '/') {
                    stk.top() /= val;
                }
            } else {
                prev_op = s[idx];
                idx++;
            }
        }

        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};
// @lc code=end
