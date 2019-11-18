/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.11%)
 * Likes:    3572
 * Dislikes: 208
 * Total Accepted:    421.8K
 * Total Submissions: 726.1K
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
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n == 0) return {};
        int n1 = 0, n2 = 0;
        string curr = "";
        dfs(n, n1, n2, curr, result);
        return result;
    }
private:
    void dfs(int n, int n1, int n2, string& curr, vector<string>& result){
        if(n1 == n && n2 == n){
            result.push_back(curr);
            return;
        }
        if(n1 < n){
            curr.push_back('(');
            dfs(n, n1 + 1,  n2, curr, result);
            curr.pop_back();
        }
        if(n2 < n1){
            curr.push_back(')');
            dfs(n, n1, n2 + 1, curr, result);
            curr.pop_back();
        }
        
    }
};
// @lc code=end

