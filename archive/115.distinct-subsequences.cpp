/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (35.84%)
 * Likes:    859
 * Dislikes: 45
 * Total Accepted:    118K
 * Total Submissions: 326.2K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * Example 1:
 * 
 * 
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * 
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * 
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.length() == 0 || t.length() == 0) return 0;
        int m = s.length(), n = t.length();
        vector<vector<unsigned long>> dp(m, vector<unsigned long>(n, 0));
        if(s[0] == t[0]) dp[0][0] = 1;
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i - 1][0];
            if(s[i] == t[0])  dp[i][0] += 1;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j];
                if(s[i] == t[j]){
                     dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

