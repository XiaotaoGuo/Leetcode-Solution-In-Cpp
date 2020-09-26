/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (63.50%)
 * Likes:    5985
 * Dislikes: 294
 * Total Accepted:    606.2K
 * Total Submissions: 954.7K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current_str = "";
        dfs(current_str, result, n, 0, 0);
        return result;
    }

private:
    void dfs(std::string& current_str, std::vector<std::string>& result, int n, int n_left, int n_right) {
        if (n_left == n && n_right == n) {
            result.push_back(current_str);
            return;
        }
        if (n_left < n_right) {
            return;
        }

        if (n_left < n) {
            current_str += '(';
            dfs(current_str, result, n, n_left + 1, n_right);
            current_str.pop_back();
        }
        
        if (n_right < n) {
            current_str += ')';
            dfs(current_str, result, n, n_left, n_right + 1);
            current_str.pop_back();
        }
    }
};
// @lc code=end

