/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.36%)
 * Likes:    2487
 * Dislikes: 110
 * Total Accepted:    229.4K
 * Total Submissions: 858.2K
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
class Solution {
public:
    int longestValidParentheses(string s) {
                stack<int> leftP;
        int leftmost = -1;
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                leftP.push(i);
            }
            else{
                if(leftP.empty()){
                    leftmost = i;
                }
                else{
                    leftP.pop();
                    if(leftP.empty()){
                        maxlen = max(maxlen, i - leftmost);
                    }
                    else{
                        maxlen = max(maxlen, i - leftP.top());
                    }
                }
            }
        }
        
        return maxlen;
    }
};
// @lc code=end

