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
        std::stack<int> index;
        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                index.push(i);  // need to find a match otherwise invalid
            }
            else {
                if (!index.empty()) {
                    index.pop();
                    maxLen = index.empty() ? std::max(maxLen, i - start + 1) : std::max(maxLen, i - index.top());
                } else {
                    start = i + 1;      // update new valid begin pos
                }
            }
        }    
        return maxLen;    
    }
};
// @lc code=end

