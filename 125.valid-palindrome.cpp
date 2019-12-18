/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (32.39%)
 * Likes:    798
 * Dislikes: 2283
 * Total Accepted:    452.9K
 * Total Submissions: 1.4M
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
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right){
            while(left < right && !isalpha(s[left]) && !isdigit(s[left])) left++;
            while(left < right && !isalpha(s[right]) && !isdigit(s[right])) right--;
            if(left == right) break;
            if(isdigit(s[left]) || isdigit(s[right])){
                if(s[left] != s[right]) return false;
            }
            else{
                int len1 = s[left] - 'A', len2 = s[right] - 'A';
                if(int(s[left]) >= 'a') len1 = s[left] - 'a';
                if(int(s[right]) >= 'a') len2 = s[right] - 'a';
                if(len1 != len2) return false;
            }
            
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

