/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.63%)
 * Likes:    8048
 * Dislikes: 575
 * Total Accepted:    1M
 * Total Submissions: 3.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        size_t len = s.length();
        
        // isPalindrome[i][j] indicate if s[i] to s[j] construct a palindrome
        std::vector<std::vector<bool>> isPalindrome(len, std::vector<bool>(len, false));
        
        // result substring begin & length
        int begin = 0;
        int maxLen = 1;

        int step = 0;
        while (step < len) {
            for (int i = 0; i < len; i++) {
                if (i + step >= len) break;
                if (s[i] != s[i + step]) continue;
                if (step <= 1 || s[i + 1] == s[i + step - 1]) {
                    isPalindrome[i][i + step] = true;
                    if (step > maxLen) {
                        maxLen = step;
                        begin = i;
                    }
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};
// @lc code=end

