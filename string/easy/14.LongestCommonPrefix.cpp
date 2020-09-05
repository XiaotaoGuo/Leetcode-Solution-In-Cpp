/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.36%)
 * Likes:    2889
 * Dislikes: 1942
 * Total Accepted:    807.8K
 * Total Submissions: 2.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix = "";
        if (strs.empty()) return prefix;
        for (int i = 0; i < strs[0].length(); i++) {
            char letter = strs[0][i];
            for (const std::string& str: strs) {
                if (i >= str.length() || str[i] != letter) return prefix;
            }
            prefix += letter;
        }
        return prefix;
    }
};
// @lc code=end

