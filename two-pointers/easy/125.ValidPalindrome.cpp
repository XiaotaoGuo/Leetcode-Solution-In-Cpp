/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (37.07%)
 * Likes:    1430
 * Dislikes: 3184
 * Total Accepted:    688K
 * Total Submissions: 1.9M
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
#include <cctype>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int front = 0, back = s.length() - 1;
        while (front < back) {
            while (front < back && !std::isalnum(s[front])) front++;
            while (front < back && !std::isalnum(s[back])) back--;
            char c1 = s[front], c2 = s[back];
            if (std::isalpha(c1)) c1 = std::toupper(c1);
            if (std::isalpha(c2)) c2 = std::toupper(c2);
            if (c1 != c2) return false;
            front++;
            back--;
        }
        return true;
    }
};
// @lc code=end

