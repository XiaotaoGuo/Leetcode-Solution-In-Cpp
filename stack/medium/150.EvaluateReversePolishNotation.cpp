/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (37.83%)
 * Likes:    1558
 * Dislikes: 521
 * Total Accepted:    279.9K
 * Total Submissions: 730.3K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, and /. Each operand may be an integer or
 * another expression.
 *
 * Note that division between two integers should truncate toward zero.
 *
 * It is guaranteed that the given RPN expression is always valid. That means
 * the expression would always evaluate to a result, and there will not be any
 * division by zero operation.
 *
 *
 * Example 1:
 *
 *
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 *
 * Example 2:
 *
 *
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 *
 * Example 3:
 *
 *
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tokens.length <= 10^4
 * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
 * range [-200, 200].
 *
 *
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> nums;
        int result = 0;
        for (auto c : tokens) {
            if (c == "+" || c == "-" || c == "/" || c == "*") {
                performOperate(nums, c[0]);
            } else {
                nums.push(std::stoi(c));
            }
        }
        return nums.top();
    }

private:
    void performOperate(std::stack<int>& nums, char op) {
        int val1 = nums.top();
        nums.pop();
        int val2 = nums.top();
        nums.pop();
        int res = val2;
        switch (op) {
            case '+':
                res += val1;
                break;
            case '-':
                res -= val1;
                break;
            case '*':
                res *= val1;
                break;
            case '/':
                res /= val1;
                break;
            default:
                break;
        }
        nums.push(res);
    }
};
// @lc code=end
