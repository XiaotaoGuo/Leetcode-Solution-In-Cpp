/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.56%)
 * Likes:    714
 * Dislikes: 2569
 * Total Accepted:    395K
 * Total Submissions: 1.2M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word (last word means the last
 * appearing word if we loop from left to right) in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a maximal substring consisting of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int ptr = s.length() - 1;
        int len = 0;
        
        while (ptr >= 0 && s[ptr] == ' ') ptr--;
        if (ptr < 0) return len;
        while (ptr >= 0 && s[ptr--] != ' ') len++;
        
        return len;
    }
};
// @lc code=end

