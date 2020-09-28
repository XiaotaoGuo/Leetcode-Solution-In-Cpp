/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (28.66%)
 * Likes:    3900
 * Dislikes: 147
 * Total Accepted:    306.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> invalid_index;
        invalid_index.push(-1);     // push a dummy index
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                invalid_index.push(i);  // need to find a match otherwise invalid
            }
            else {
                invalid_index.pop();
                if (!invalid_index.empty()) {
                    maxLen = std::max(maxLen, i - invalid_index.top()); // update result
                } else {
                    invalid_index.push(i);
                }
            }
        }    
        return maxLen;    
    }
};
// @lc code=end

