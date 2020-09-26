/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.17%)
 * Likes:    5694
 * Dislikes: 238
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "{[]}"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {

        if (s.length() % 2 == 1) return false;

        std::stack<char> stk;
        std::unordered_map<char, char> pairs ({
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        });

        for (int i = 0; i < s.length(); i++) {
            if (pairs.count(s[i])) {
                stk.push(s[i]);
            } else {
                if (stk.empty() || s[i] != pairs[stk.top()]) return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};
// @lc code=end

