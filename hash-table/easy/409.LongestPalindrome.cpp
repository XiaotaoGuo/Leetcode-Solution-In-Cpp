/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (50.24%)
 * Likes:    1137
 * Dislikes: 86
 * Total Accepted:    164.9K
 * Total Submissions: 320.7K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
        
        std::unordered_map<char, int> count_letter;
        
        for (const char& letter: s) {
            count_letter[letter]++;
        }
        
        int length = 0;
        bool has_odd = false;
        for (auto iter = count_letter.begin(); iter != count_letter.end(); iter++) {
            if (iter->second % 2) has_odd = true;
            length += iter->second % 2 == 0 ? iter->second : iter->second - 1;
        }
        
        if (has_odd) length += 1;
        
        return length;
        
    }
};
// @lc code=end

