/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (49.28%)
 * Likes:    1789
 * Dislikes: 213
 * Total Accepted:    238.5K
 * Total Submissions: 483.8K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given a string s and a string t, check if s is subsequence of t.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 * 
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * Both strings consists only of lowercase characters.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int n1 = s.length(), n2 = t.length();

        // isSubseq[i][k] indicates whether s[0::i] is subsequence of t[0::j]
        std::vector<std::vector<bool>> isSubseq(n1 + 1, std::vector<bool>(n2 + 1, false));

        for (int j = 0; j <= n2; j++) isSubseq[0][j] = true;
        for (int i = 1; i <= n1; i++) isSubseq[i][0] = false;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (isSubseq[i][j - 1]) {
                    // if s is already a subsequence of t, it must be subsequence of t + any letter
                    isSubseq[i][j] = true;
                } else {
                    isSubseq[i][j] = (s[i-1] == t[j-1]) && isSubseq[i - 1][j - 1];
                }
            }
        }

        return isSubseq[n1][n2];    
    }
};
// @lc code=end

