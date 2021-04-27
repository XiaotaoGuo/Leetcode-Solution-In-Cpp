/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (38.12%)
 * Likes:    2182
 * Dislikes: 182
 * Total Accepted:    207.6K
 * Total Submissions: 541.9K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing an expression, implement a basic calculator to
 * evaluate it.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: s = " 2-1 + 2 "
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
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
        int result = 0;
        int sign = 1;
        int idx = 0;
        while (idx < s.length()) {
            if (std::isdigit(s[idx])) {
                int num = 0;
                while (idx < s.length() && std::isdigit(s[idx])) {
                    num *= 10;
                    num += (s[idx] - '0');
                    idx++;
                }
                result += sign * num;
                idx--;
            } else if (s[idx] == '+') {
                sign = 1;
            } else if (s[idx] == '-') {
                sign = -1;
            } else if (s[idx] == '(') {
                // use the top of stack as initial result and continue
                // computation
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (s[idx] == ')') {
                result *= stk.top();
                stk.pop();
                result += stk.top();
                stk.pop();
            }
            idx++;
        }

        return result;
    }
};
// @lc code=end
