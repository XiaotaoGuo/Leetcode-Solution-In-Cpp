/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.95%)
 * Likes:    4746
 * Dislikes: 425
 * Total Accepted:    714.4K
 * Total Submissions: 2.5M
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
class Solution {
public:
    string longestPalindrome(string s) {
                if(!s.length()) return "";
        string result = s.substr(0, 1);
        int maxLen = 1;
        int mid = 0;
        while(mid < s.length() && (s.length() - 1 - mid)*2+1 > maxLen){
            int len = 1;
            int l = mid - 1, r = mid + 1;
            while(r < s.length() && s[mid] == s[r]){
                len++;
                r++;
            }
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                l--;
                r++;
                len+=2;
                
            }
            string currResult = s.substr(l + 1, len);
            if(len > maxLen){
                result = currResult;
                maxLen = len;
            }
            mid++;
        }
        return result;
    }
};
// @lc code=end

