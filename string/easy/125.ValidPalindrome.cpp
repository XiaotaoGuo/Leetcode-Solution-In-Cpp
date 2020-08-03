/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (35.88%)
 * Likes:    1270
 * Dislikes: 3023
 * Total Accepted:    616.8K
 * Total Submissions: 1.7M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <locale> 

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !std::isalnum(s[left])) left++;
            while (right > left && !std::isalnum(s[right])) right--;

            if (left == right) break;
            
            if (std::isalpha(s[left]) && (std::toupper(s[left]) != std::toupper(s[right]))) return false;
            else if (std::isdigit(s[left]) && s[left] != s[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};
// @lc code=end

